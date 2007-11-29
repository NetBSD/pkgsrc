/* $NetBSD: cvsdiff2patch.c,v 1.1.1.1 2007/11/29 10:11:13 bjs Exp $ */

/*
 * Copyright (c) 2003 Research Engineering Development Inc.
 * All rights reserved.
 * Author: Alfred Perlstein <alfred@FreeBSD.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: cvsdiff2patch.c,v 1.1.1.1 2007/11/29 10:11:13 bjs Exp $
 */

/*
 * Convert crappy CVS diffs into something that patch(1) understands.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <err.h>

char *	xstrdup(const char *str);
int	fileline(const char *line, int ch);

char *
xstrdup(const char *str)
{
	char *ret;

	ret = strdup(str);
	if (str == NULL)
		err(1, "strdup");
	return (ret);
}

int
fileline(const char *line, int ch)
{
	int i;

	for (i = 0; i < 3; i++) {
		if (line[i] != ch)
			return (0);
	}
	if (line[strlen(line) - 1] == ch) {
		return (0);
	}
	return (1);
}

int
main(void)
{
	char *line, *filepath;
	size_t len;
	const char *indexstr = "Index:";
	size_t indexlen;

	fprintf(stderr,
	    "Cvsdiff2patch (c) 2003 Research Engineering Development\n");

	filepath = NULL;
	indexlen = strlen(indexstr);

	while ((line = fgetln(stdin, &len)) != NULL) {
		line[len - 1] = '\0';
		if (len > indexlen && strncmp(line, indexstr, indexlen) == 0) {
			char *p;

			p = memchr(line, ' ', len);
			if (p != NULL) {
				p++;
				free(filepath);
				filepath = xstrdup(p);
			}
			continue;
		}
		if (len > 4 &&
		    (fileline(line, '-') ||
		     fileline(line, '+') ||
		     fileline(line, '*'))) {
			line[3] = '\0';
			printf("%s %s\n", line, filepath);
			continue;
		}
		line[len - 1] = '\n';
		switch (*line) {
		case ' ':
		case '+':
		case '-':
		case '!':
		case '@':
		case '*':
			fwrite(line, 1, len, stdout);
			break;
		default:
#if 0
			printf("blah! ");
			fwrite(line, 1, len, stdout);
#endif
			break;
		}
	}
	return (0);
}
