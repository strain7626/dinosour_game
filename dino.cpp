#include <stdio.h>
#include <windows.h>

int map[20][60];
int object_graphic[5][5][5]{
{
	{0, 0, 0, 7, 6},
	{4, 0, 0, 6, 6},
	{6, 6, 6, 6, 0},
	{0, 6, 6, 6, 0},
	{0, 0, 5, 5, 0},
},
{
	{0, 0, 4, 0, 0},
	{0, 0, 3, 4, 0},
	{0, 4, 3, 3, 0},
	{0, 3, 3, 0, 0},
	{0, 0, 3, 0, 0},
},
{},
{},
{},
};


void gotoxy(int x,int y);
void game();
void print();
void pixel(int w);
void mapset();
void object();
void player();
int main(){
	mapset();
	game();
	


	return 0;
}
void game(){
	while(1){
		//move
		//score
		player(); 
		object();
		print();
		Sleep(5);
	}
}
void print(){
	static int map2[20][60] = {0};
	for(int y = 0; y < 20; y++)
		for(int x = 0; x < 60; x++)
			if(map[y][x] != map2[y][x]){
				gotoxy(2*x,y);
				pixel(map[y][x]);
				map2[y][x] = map[y][x];
			}
}
void pixel(int w){
	if(w == 0)
		printf("  ");
	else if(w == 1)
		printf("■");
	else if(w == 2)
		printf("─");
	else if(w == 3)
		printf("▥");
	else if(w == 4)
		printf("△");
	else if(w == 5)
		printf("▽");
	else if(w == 6)
		printf("□");
	else if(w == 7)
		printf("▣");
}
void mapset(){
	for(int y = 0; y < 20; y++)
		for(int x = 0; x < 60; x++)
			map[y][x] = 0;
		
	for(int i = 0; i < 60; i++){
		map[15][i] = 1;
	}
	for(int i = 0; i < 60; i++){
		map[19][i] = 2;
	}
}
void object(){
	for(int y = 10; y < 15; y++){
		for(int x = 30; x < 35; x++){
			map[y][x] = object_graphic[1][y-10][x-30];
		}
	} 
}
void player(){
	for(int y = 10; y < 15; y++){
		for(int x = 5; x < 10; x++){
			map[y][x] = object_graphic[0][y-10][x-5];
		}
	} 
}


void gotoxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
