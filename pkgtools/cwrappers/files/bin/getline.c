#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"

ssize_t
getline(char **lineptr, size_t *len, FILE *fp)
{
	char *iter, *eos;
	int ch;

	if (*len == 1) {
		free(*lineptr);
		*len = 0;
	}
	if (*len == 0) {
		*lineptr = malloc(128);
		if (*lineptr == NULL)
			return -1;
		*len = 128;		
	}

	iter = *lineptr;
	for (;;) {
		eos = *lineptr + *len - 1;

		while (iter < eos) {
			ch = getc_unlocked(fp);
			if (ch == -1)
				break;
			*iter++ = ch;
			if (ch == '\n') {
				*iter = '\0';
				return iter - *lineptr;
			}
		}
		if (iter == *lineptr)
			return -1;
		if (iter < eos) {
			*iter = '\0';
			return iter - *lineptr;
		}

		iter = realloc(*lineptr, *len * 2);
		if (iter == NULL)
			return -1;
		*lineptr = iter;
		iter += *len - 1;
		*len *= 2;
	}
}
