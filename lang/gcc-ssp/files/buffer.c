/*	$NetBSD: buffer.c,v 1.1 2001/06/30 16:16:11 kent Exp $	*/

#include <stdio.h>

int main(int argc, char* argv[]) {
	char buffer[10];
	strcpy(buffer, argv[1]);
	return 0;
}
