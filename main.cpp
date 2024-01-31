#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
double f[105][105][105][3];
int x, y, now, sheng1 = 5,sheng2= 5;

int ziDan(){
	int te = rand()%(x+y);
	if (te < x){
		x--;
		return 0;
	}
	y--;
	return 1;
}

void AiInit() {
	double die = rand() % 50 / 100.0;
	for (int k = 0;k <= 100; k++) {
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (k == 0) 
					f[i][j][k][0] = f[i][j][k][1] = f[i][j][k][2] = 0;
				else if (i == 0 && j == 0) 
					continue;
				else if (i == 0) 
					f[i][j][k][0] = 0,f[i][j][k][1] = 1,f[i][j][k][2] = max(f[i][j][k][0],f[i][j][k][1]);
				else if(j == 0) 
					f[i][j][k][0] = 1,f[i][j][k][1] = 0,f[i][j][k][2] = max(f[i][j][k][0],f[i][j][k][1]);
				else 
					f[i][j][k][0] = (f[i-1][j][k][2]*i+(f[i][j-1][k-1][2]-die)*j)/(i+j), 
					f[i][j][k][1] = 1.0*j/(i+j), 
					f[i][j][k][2] = max(f[i][j][k][0],f[i][j][k][1]);
			}
		}
	}
}

signed main(){
	srand(time(NULL));
	AiInit();
	while (1){
		goto1 : ;
		system("cls");
		if (x == 0 && y == 0) x = rand()%5+1,y = rand()%5+1;
		printf("当前%d空弹，%d实弹\n",x,y);
		printf("敌方：");
		for (int i = 1;i <= sheng2;i++) cout << "■";
		printf("\n我方：");
		for (int i = 1;i <= sheng1;i++) cout << "■";
		puts("");
		system("pause");
		if (now){
			while (f[x][y][sheng2][0] > f[x][y][sheng2][1]){
				printf("对方对自己发射..."),Sleep(1000);
				int te = ziDan();
				if (te == 0) printf("空弹\n");
				else{
					printf("实弹\n"),sheng2--;
					if (sheng2 == 0) printf("你TM赢了！"),exit(0);
				}
				if (x == 0 && y == 0){
					now ^= 1;
					goto goto1;
				}
			}
			printf("对方对你发射..."),Sleep(1000);
			int te = ziDan();
			if (te == 0) printf("空弹\n");
			else{
				printf("实弹\n"),sheng1--;
				if (sheng1 == 0) printf("你TM输了！逊了啦"),exit(0);
			}
			if (x == 0 && y == 0){
				now ^= 1;
				goto goto1;
			}
		}else{
			int te;
			while (1){
				printf("你要干嘛？（1对对方发射，0对自己发射）"); 
				while (cin >> te && te != 0 && te != 1) printf("你干嘛！\n");
				if (te == 0){
					printf("你对自己发射..."),Sleep(1000);
					int te = ziDan();
					if (te == 0) printf("空弹\n");
					else{
						printf("实弹\n"),sheng1--;
						if (sheng1 == 0) printf("你TM输了！逊了啦"),exit(0);
					}
					if (x == 0 && y == 0){
						now ^= 1;
						goto goto1;
					}
				}else{
					printf("你对对方发射..."),Sleep(1000);
					int te = ziDan();
					if (te == 0) printf("空弹\n");
					else{
						printf("实弹\n"),sheng2--;
						if (sheng2 == 0) printf("你TM赢了！"),exit(0);
					}
					break;
				}
				if (x == 0 && y == 0){
					now ^= 1;
					goto goto1;
				}
			}
		}
		now ^= 1;
		system("pause");
		system("cls");
	}

	return 0;
}
