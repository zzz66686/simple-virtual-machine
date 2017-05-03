// plaintext_crackme.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>


#define D_SIZE 100
#define KEY_LEN 48


#define KEY1 0xf33746e6
#define KEY2 0x54962766
#define KEY3 0x02542601
#define KEY4 0x547702e7
#define KEY5 0x1636c2f6
#define KEY6 0x16865747

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Hello World!\n");
		return 0;
	}
	if (strlen(argv[1]) > KEY_LEN) {
		return 0;
	}

	unsigned char *y = new unsigned char[D_SIZE];
	memcpy(y, argv[1], 50);


	for (int i = 0; i <= 0x2F; i++, y++) {
		if (*y == 0x0){
		return 0;
        }
		if ((*y < '0') || (*y > 'F')) {
			return 0;
		}
		if (*y <= '9') {
			continue;
		}
		if (*y < 'A') {
			return 0;
		}
	}
	
	y--;

	unsigned int temp = 0;
	for (int i = 0; i < 8; i++,y--) {
		temp *= 0x10;
		if (*y - 0x30 <= 9) {
			temp += *y - 0x30;
		}
		else {
			temp += *y - 0x30 - 0x7;
		}
	}
	if (temp != KEY1) {
		return 0;
	}

	temp = 0;
	for (int i = 0; i < 8; i++, y--) {
		temp *= 0x10;
		if (*y - 0x30 <= 9) {
			temp += *y - 0x30;
		}
		else {
			temp += *y - 0x30 - 0x7;
		}
	}
	if (temp != KEY2) {
		return 0;
	}

	temp = 0;
	for (int i = 0; i < 8; i++, y--) {
		temp *= 0x10;
		if (*y - 0x30 <= 9) {
			temp += *y - 0x30;
		}
		else {
			temp += *y - 0x30 - 0x7;
		}
	}
	temp--;
	if (temp != KEY3) {
		return 0;
	}


	temp = 0;
	for (int i = 0; i < 8; i++, y--) {
		temp *= 0x10;
		if (*y - 0x30 <= 9) {
			temp += *y - 0x30;
		}
		else {
			temp += *y - 0x30 - 0x7;
		}
	}
	temp++;
	if (temp != KEY4) {
		return 0;
	}

	temp = 0;
	for (int i = 0; i < 8; i++, y--) {
		temp *= 0x10;
		if (*y - 0x30 <= 9) {
			temp += *y - 0x30;
		}
		else {
			temp += *y - 0x30 - 0x7;
		}
	}
	if (temp != KEY5) {
		return 0;
	}


	temp = 0;
	for (int i = 0; i < 8; i++, y--) {
		temp *= 0x10;
		if (*y - 0x30 <= 9) {
			temp += *y - 0x30;
		}
		else {
			temp += *y - 0x30 - 0x7;
		}
	}
	if (temp != KEY6) {
		return 0;
	}


	printf("Nice!!! U got it!\n");
	
	y++;
	delete[] y;

	return 0;
}
