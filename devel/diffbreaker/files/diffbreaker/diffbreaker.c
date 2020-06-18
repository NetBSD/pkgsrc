/* $NetBSD: diffbreaker.c,v 1.8 2020/06/18 13:40:17 nat Exp $ */

/*-
 * Copyright (c) 2018, 2019 Nathanial Sloss <nathanialsloss@yahoo.com.au>
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <curses.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t finalize_context(ssize_t context, ssize_t current, ssize_t secthead,
		     ssize_t first, ssize_t part, ssize_t origoffs,
		     ssize_t newoffs, ssize_t last, ssize_t pos);
ssize_t update_context(ssize_t lines, ssize_t current, ssize_t last);
ssize_t get_context(ssize_t current, ssize_t last, ssize_t num);
void print_buffer(ssize_t myLine, ssize_t dispLines);
void parse_buffer(char *outfile, bool incremental, uint32_t *filesuffix);
void read_data_to_buffer(char *myFile);
void free_buffers_actions(void);
void setup_screen(void);
void mark_dirty(void);
#ifndef __dead
#define __dead __attribute__((__noreturn__))
#endif
#ifdef __linux__
extern char *__progname;
#define getprogname()	__progname
#endif

__dead static void usage(void);

int dispLine, promptLine, scrcols, scrlines;
int displayLines;
WINDOW *mywin = NULL;
static char *buffer;
static char *newbuffer;
static char *action;
static char *newaction;
static ssize_t currentLine, totalLines, cpl;

#define ORIGBUF(x)	(buffer + ((x) * cpl))
#define NEWBUF(x)	(newbuffer + ((x) * cpl))

#define COLORTEXT(x)				\
	do {					\
		if (has_colors())			\
			attrset(COLOR_PAIR(x));	\
		else				\
			attrset(A_REVERSE);	\
	} while (0)						

#define NORMALTEXT				\
	do {					\
		if (has_colors())			\
			attrset(COLOR_PAIR(1));	\
		else				\
			attrset(A_NORMAL);	\
	} while (0)						
void
mark_dirty(void)
{
	bool writetome = false, display = false;
	bool pending = false, writesect = false;
	ssize_t i, j = 0, last = 0, myfile = 0;
	size_t len = (size_t)cpl;

	j = 0;
	for (i = 0; i < totalLines; i++) {
		switch (action[i]) {
		case 2: /* Selected */
			if (*ORIGBUF(i) == '-') {
				continue;
			}
			if (*ORIGBUF(i) == '+') {
				strncpy(NEWBUF(j), ORIGBUF(i), len);
				*NEWBUF(j) = ' ';
				action[j] = 0;
			}
			break;
		case 5: /* @@ marker */
			if (pending == false && writesect == false)
				j = last;
			last = j;
			pending = false;
			writesect = false;
			action[j] = action[i];
			strncpy(NEWBUF(j), ORIGBUF(i), len);
			break;
		case 6: /* --- */
			if (pending == false && writesect == false)
				j = last;
			if (writetome == false)
				j = myfile;
			myfile = j;
			pending = true;
			writetome = false;
			writesect = true;
			strncpy(NEWBUF(j), ORIGBUF(i), len);
			action[j] = action[i];
			break;
		case 7: /* +++ */
			strncpy(NEWBUF(j), ORIGBUF(i), len);
			action[j] = action[i];
			break;
		case 1: /* unselected change */
			display = true;
			writesect = true;
			writetome = true;
			/* fallthrough */
		default:
			strncpy(NEWBUF(j), ORIGBUF(i), len);
			action[j] = action[i];
			break;
		}
		strncpy(ORIGBUF(j), NEWBUF(j), len);
		j++;
	}
	totalLines = display ? j-- : 0;

	return;
}

ssize_t
update_context(ssize_t lines, ssize_t current, ssize_t last)
{
	ssize_t j, l = 0;
	j = current;
	while (lines > 0) {
		if (*ORIGBUF(last + l) == '+') {
			l++;
			continue;
		}
		sprintf(NEWBUF(j), "%s", ORIGBUF(last + l++));
		*NEWBUF(j++) = ' ';
		if (last + l > totalLines)
			break;
		lines--;
	}

	return j;
}

ssize_t
get_context(ssize_t current, ssize_t last, ssize_t num)
{
	ssize_t context = 0, tmpcontext = 0, i, j, l;

	i = current - 1;
	j = last;

	for (l = 0; tmpcontext < num; l++) {
		if ((l + i) > totalLines)
			break;
		if (i - l >= 0)
			context++;
		if (action[i - l] == 2)
			goto next;
		if (action[i - l] != 6 && *ORIGBUF(i - l) == '-') {
			tmpcontext++;
			continue;
		}
		if (*ORIGBUF(i - l) == ' ') {
			tmpcontext++;
			continue;
		}
next:
		if (context == tmpcontext) {
			j = update_context(tmpcontext, j, i - context - 1);
			tmpcontext = 0;
			num -= tmpcontext;
		}
		if (action[i - l] == 6 || action[i - l] == 7)
			break;
		if (action[i - l] == 2)
			break;
	}
	if (l > 0)
		l--;
	if (tmpcontext)
		j = update_context(tmpcontext, j, i - l);

	return j;
}

ssize_t
finalize_context(ssize_t context, ssize_t current, ssize_t secthead,
		 ssize_t first, ssize_t part, ssize_t origoffs,
		 ssize_t newoffs, ssize_t last, ssize_t pos)
{
	ssize_t blanks, orig, addition, l;
	ssize_t fixoffs, j, begblanks;
	bool firstf;

	fixoffs = secthead;
	j = current;

	firstf = false;
	begblanks = 0;
	j = update_context(context, j, last);
	blanks = orig = addition = 0;
	for (l = secthead + 1; l < j; l++) {
		if (*NEWBUF(l) == ' ') {
			if (!firstf)
				begblanks++;
			blanks++;
		}
		if (*NEWBUF(l) == '-') {
			firstf = true;
			orig++;
		}
		if (*NEWBUF(l) == '+') {
			firstf = true;
			addition++;
		}
	}
	sprintf(NEWBUF(fixoffs), "@@ %ld,%ld +%ld,%ld @@\n",
	    origoffs - first + part + (begblanks - context),
	    orig + blanks, newoffs +
	    first - part - (begblanks - context), addition + blanks);

	newaction[secthead] = action[pos];

	return j;
}

void
parse_buffer(char *outfile, bool incremental, uint32_t *filesuffix)
{
	ssize_t origoffs = 0, newoffs = 0, first = 0, last = 0, part = 0;
	ssize_t final = 0, context = 0, fixoffs = 0, i, j, adj;
	bool found = false, writecount = false;
	char tmpstr[100], tmpstr1[100];
	FILE *myfile = NULL;

	j = 0;
	for (i = 0; i < totalLines; i++) {
		switch (action[i]) {
		case 6:		/* --- */
			if (found == true) {
				j = finalize_context(context, j, fixoffs, first,
				    part, origoffs, newoffs, last, i);
				final = j;
				last = i;
				found = false;
			}
			first = 0;
			if (writecount == false)
				j = final;
			newaction[j] = action[i];
			sprintf(NEWBUF(j++), "%s", ORIGBUF(i));
			break;
		case 5:		/* @@ */
			if (found == true) {
				j = finalize_context(context, j, fixoffs, first,
				    part, origoffs, newoffs, last, i);
				final = j;
				last = i;
				found = false;
			}
			first = 0;
			part = 0;
			fixoffs = j;

			// XXX: this was uninitialized according to valgrind
			// check the sscanf return?
			tmpstr[0] = '\0';
			tmpstr1[0] = '\0';
			sscanf(ORIGBUF(i), "@@ %s %s\n", tmpstr, tmpstr1);
			char *rest = NULL;
			origoffs = strtol(tmpstr, &rest, 10);
			rest++;
			(void)strtol(rest, &rest, 10);
			newoffs = strtol(tmpstr1, &rest, 10);
			rest++;
			//(void)strtol(rest, &rest, 10);
			break;
		case 1: /* unselected change */
			if (part == 0)
				part = i;
			if (part && !found && *ORIGBUF(i) == '+')
				part++;
			break;
		case 2: /* selected */
			adj = 0;
			if (!found) {
				writecount = true;
				context = 0;
				first = i;
				last = i;
				j++;
				adj = 3;
				if (part == 0)
					part = i;
			
				found = true;
			}
			j = get_context(i, j, i - last + adj);
			sprintf(NEWBUF(j++), "%s", ORIGBUF(i));
			last = i;
			if (*ORIGBUF(i) == '-')
				last++;
			final = j;
			context = 3;
			break;
		case 7:
		case 4:
			writecount = false;
			newaction[j] = action[i];
			sprintf(NEWBUF(j++), "%s", ORIGBUF(i));
		default:
			break;
		}
	}
	if (context && found)
		j = finalize_context(context, j, fixoffs, first,
		    part, origoffs, newoffs, last, i);

	if (writecount == false && found == false)
		j = final;

	char tmppath [512];
	if (incremental)
		snprintf(tmppath, sizeof(tmppath), "%s.%d.diff", outfile,
		    *filesuffix);
	else
		snprintf(tmppath, sizeof(tmppath), "%s", outfile);

	if (j == 0)
		return;

	if (!strcmp(tmppath, "-"))
		myfile = stderr;
	else if ((myfile = fopen(tmppath, "a")) == NULL) {
		free_buffers_actions();
		errx(errno, "Could not create/open file(s) for writing.");
		/* Not reached */
	}
	for (i = 0; i < j; i++)
		fprintf(myfile, "%s", NEWBUF(i));
	fclose(myfile);

	*filesuffix += 1;
	return;
}

void
free_buffers_actions(void)
{
	free(buffer);
	free(newbuffer);
	free(newaction);
	free(action);

	buffer = NULL;
	newbuffer = NULL;
	newaction = NULL;
	action = NULL;

}

void
read_data_to_buffer(char *myFile)
{
	char data, line[512], myaction = 0;
	ssize_t nr;
	ssize_t l = 0, j = 0, n = 0;
	int fd, i;

	if ((fd = open(myFile, O_RDONLY)) < 0)
		errx(errno, "Error Opening file %s.", myFile);

	memset(line, 0, sizeof(line));
	i = 0;
	cpl = 0;
	while ((nr = read(fd, line, sizeof(line))) > 0) {
		for (i = 0; i < nr; i++) {
			j++;
			if (line[i] == '\n') {
				n++;
				if (j > cpl)
					cpl = j;
				j = 0;
			}
		}
	}
	cpl++;
	l = n;

	size_t totalalloc = (size_t)(l * cpl);
	if (totalalloc <= 0 || l <= 0)
		errx(EXIT_FAILURE, "File mem calc error.");

	if ((newaction = calloc((size_t)l, sizeof(*newaction))) == NULL)
		errx(errno, "File mem alloc error.");
	if ((action = calloc((size_t)l, sizeof(*action))) == NULL) {
		free(newaction);
		errx(errno, "File mem alloc error.");
	}
	if ((buffer = calloc(totalalloc, sizeof(*buffer))) == NULL) {
		free(action);
		free(newaction);
		errx(errno, "File mem alloc error.");
	}
	if ((newbuffer = calloc(totalalloc, sizeof(*newbuffer))) == NULL) {
		free(buffer);
		free(action);
		free(newaction);
		errx(errno, "File mem alloc error.");
	}
	memset(newaction, 0, (size_t)l * sizeof(*newaction));
	memset(action, 0, (size_t)l * sizeof(*action));
	memset(buffer, 0, (size_t)totalalloc * sizeof(*buffer));
	memset(newbuffer, 0, (size_t)totalalloc * sizeof(*newbuffer));

	j = n = 0;
	lseek(fd, 0, SEEK_SET);
	while ((nr = read(fd, line, sizeof(line))) > 0) {
		for (i = 0; i < nr; i++) {
			data = line[i];
			*(ORIGBUF(j) + n++) = data;
			if (data == '\n') {
				myaction = 0;
				if (*ORIGBUF(j) == '-' && *(ORIGBUF(j) + 1) ==
				    '-' && *(ORIGBUF(j) + 2) == '-')
					myaction = 6;
				else if (*ORIGBUF(j) == '+' && *(ORIGBUF(j) + 1) ==
				    '+' && *(ORIGBUF(j) + 2) == '+')
					myaction = 7;
				else if (*ORIGBUF(j) == '+' && myaction != 7)
					myaction = 1;
				else if (*ORIGBUF(j) == '-' && myaction != 6)
					myaction = 1;
				else if (*ORIGBUF(j) == '@' && *(ORIGBUF(j) + 1) ==
				    '@')
					myaction = 5;
				else if (*ORIGBUF(j) != ' ')
					myaction = 4;
				action[j] = myaction;
				if (action[j] != 4)
					j++;
				else {
					memset(ORIGBUF(j), 0, (size_t)cpl);
					action[j] = 0;
				}
				n = 0;
			}
		}
	}

	totalLines = j--;

	close(fd);

	return;
}

void
print_buffer(ssize_t myLine, ssize_t dispLines)
{
	static char tmpline[512];
	ssize_t i, m, startLine;
	int j = 0;

	startLine = (myLine / dispLines) * dispLines;
	move (0, 0);
	for (i = startLine; i < (startLine + dispLines) && i < totalLines;
	    i++) {
		NORMALTEXT;
		if (action[i] == 2 && i == myLine)
			COLORTEXT(4);
		else if (i == myLine)
			COLORTEXT(2);
		else if (action[i] == 2)
			COLORTEXT(5);
		else if (action[i] == 4)
			COLORTEXT(5);
		else if (action[i] == 5)
			COLORTEXT(3);
		else if (action[i] == 6 || action[i] == 7)
			COLORTEXT(3);
		if (action[i] != 9) {
			snprintf(tmpline, sizeof(tmpline), "%s", ORIGBUF(i));
			int p = 0;
			ssize_t llen = (ssize_t)strlen(tmpline);
			char tmpstr[1024];
			for (m = 0; m < llen; m++) {
				if ((tmpline[m] < ' ') && (tmpline[m] != '\t')
				    && (tmpline[m] != '\n')) {
					snprintf(tmpstr+p, (size_t)(1024 - p), "%s",
					    unctrl(tmpline[m]));
					p += (int)strlen(unctrl(tmpline[m])) - 1;
				} else if (tmpline[m] == '\t') {
					snprintf(tmpstr+p, (size_t)(1024 - p),  "    ");
					p += 3;
				} else
					snprintf(tmpstr+p, (size_t)(1024 - p), "%c", tmpline[m]);
				p++;
			}
			p = 0;
			llen = (ssize_t)strlen(tmpstr);
			for (m = 0; m < llen && p < (scrcols - 1); m++)
				mvprintw(j, p++, "%c", tmpstr[m]);
			j++;
		}
	}
	NORMALTEXT;
	for (; i < startLine + dispLines; i++) {
		mvprintw(j, 0, "\n");
		j++;
	}

	COLORTEXT(2);
	mvprintw(promptLine, 0, "%ld lines remaining", totalLines);

	refresh();
	return;
}

void
usage(void)
{
	fprintf(stderr, "Usage: %s [-s] -i infile -o outpath/file\n",
	    getprogname());

	exit(EXIT_FAILURE);
	/* Not reached */
}

void
setup_screen(void)
{
	if (!(mywin = initscr())) {
		free_buffers_actions();
		errx(EXIT_FAILURE, "\nUnknown terminal type.");
	}

	scrlines = LINES;
	scrcols = COLS;

	if (scrlines <= 0 || scrcols <= 0) {
		delwin(mywin);
		endwin();

		mywin = NULL;
		free_buffers_actions();
		errx(EXIT_FAILURE, "\nUnknown screen dimensions.");
	}
	promptLine = scrlines - 1;
	displayLines = scrlines - 2;
	if (has_colors()) {
		start_color();
 
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		init_pair(2, COLOR_BLACK, COLOR_WHITE);
		init_pair(3, COLOR_WHITE, COLOR_BLUE);
		init_pair(4, COLOR_WHITE, COLOR_YELLOW);
		init_pair(5, COLOR_WHITE, COLOR_GREEN);
		init_pair(6, COLOR_WHITE, COLOR_RED);

		NORMALTEXT;
	}

}

int
main(int argc, char *argv[])
{
	char *infile = NULL, *outfile = NULL;
	bool incremental = false;
	uint32_t filesuffix = 1;
	int ch;
	char myKey;

	dispLine = 0;
	currentLine = 0;

	while ((ch = getopt(argc, argv, "si:o:")) != EOF) {
		switch (ch) {
		case 's':
			incremental = true;
			break;
		case 'i':
			infile = (char *)(optarg);
			break;
		case 'o':
			outfile = (char *)(optarg);
			break;
		default:
			usage();
			/* Not reached */
		}
	}
	argc -= optind;
	argv += optind;

	if (infile == NULL || outfile == NULL) {
		usage();
		/* Not reached */
	}

	read_data_to_buffer(infile);

	setup_screen();
	mark_dirty();
	print_buffer(currentLine, (size_t)(displayLines + 1));
	COLORTEXT(2);

	for (;;) {
		myKey = (char)getch();
		if (myKey == 'q')
			break;
		if (myKey == 'k' && currentLine > 0)
			currentLine--;
		if (myKey == ' ') {
			if (action[currentLine] == 1)
				action[currentLine] = 2;
			else if (action[currentLine] == 2)
				action[currentLine] = 1;
			if (currentLine < totalLines -1)
				currentLine++;
		}
		if (myKey == 'j' && currentLine < totalLines - 1)
			currentLine++;
		if (myKey == 'G')
			currentLine = totalLines - 1;
		if (myKey == 'g')
			currentLine = 0;
		if (myKey == 'l') {
			if (is_term_resized(LINES, COLS)) {
				resizeterm(LINES, COLS);
				scrcols = COLS;
				scrlines = LINES;
				promptLine = scrlines - 1;
				displayLines = scrlines - 2;
			}
		}
		if (myKey == 'w') {
			currentLine = 0;
			parse_buffer(outfile, incremental, &filesuffix);
			mark_dirty();
			if (totalLines <= 0)
				break;
		}
		print_buffer(currentLine, (size_t)(displayLines + 1));
	}

	delwin(mywin);
	endwin();

	free_buffers_actions();
	mywin = NULL;

	return EXIT_SUCCESS;
}
