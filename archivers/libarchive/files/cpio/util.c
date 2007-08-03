/*-
 * Copyright (c) 2003-2007 Tim Kientzle
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "cpio_platform.h"
__FBSDID("$FreeBSD$");

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#include <ctype.h>
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif
#include <stdio.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "cpio.h"

static void	cpio_vwarnc(struct cpio *, int code,
		    const char *fmt, va_list ap);

static void
cpio_vwarnc(struct cpio *cpio, int code, const char *fmt, va_list ap)
{
	fprintf(stderr, "%s: ", cpio->progname);
	vfprintf(stderr, fmt, ap);
	if (code != 0)
		fprintf(stderr, ": %s", strerror(code));
	fprintf(stderr, "\n");
}

void
cpio_warnc(struct cpio *cpio, int code, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	cpio_vwarnc(cpio, code, fmt, ap);
	va_end(ap);
}

void
cpio_errc(struct cpio *cpio, int eval, int code, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	cpio_vwarnc(cpio, code, fmt, ap);
	va_end(ap);
	exit(eval);
}

/*
 * Read lines from file and do something with each one.  If option_null
 * is set, lines are terminated with zero bytes; otherwise, they're
 * terminated with newlines.
 *
 * This uses a self-sizing buffer to handle arbitrarily-long lines.
 * If the "process" function returns non-zero for any line, this
 * function will return non-zero after attempting to process all
 * remaining lines.
 */
int
process_lines(struct cpio *cpio, const char *pathname,
    int (*process)(struct cpio *, const char *))
{
	FILE *f;
	char *buff, *buff_end, *line_start, *line_end, *p;
	size_t buff_length, bytes_read, bytes_wanted;
	int separator;
	int ret;

	separator = cpio->option_null ? '\0' : '\n';
	ret = 0;

	if (strcmp(pathname, "-") == 0)
		f = stdin;
	else
		f = fopen(pathname, "r");
	if (f == NULL)
		cpio_errc(cpio, 1, errno, "Couldn't open %s", pathname);
	buff_length = 8192;
	buff = malloc(buff_length);
	if (buff == NULL)
		cpio_errc(cpio, 1, ENOMEM, "Can't read %s", pathname);
	line_start = line_end = buff_end = buff;
	for (;;) {
		/* Get some more data into the buffer. */
		bytes_wanted = buff + buff_length - buff_end;
		bytes_read = fread(buff_end, 1, bytes_wanted, f);
		buff_end += bytes_read;
		/* Process all complete lines in the buffer. */
		while (line_end < buff_end) {
			if (*line_end == separator) {
				*line_end = '\0';
				if ((*process)(cpio, line_start) != 0)
					ret = -1;
				line_start = line_end + 1;
				line_end = line_start;
			} else
				line_end++;
		}
		if (feof(f))
			break;
		if (ferror(f))
			cpio_errc(cpio, 1, errno,
			    "Can't read %s", pathname);
		if (line_start > buff) {
			/* Move a leftover fractional line to the beginning. */
			memmove(buff, line_start, buff_end - line_start);
			buff_end -= line_start - buff;
			line_end -= line_start - buff;
			line_start = buff;
		} else {
			/* Line is too big; enlarge the buffer. */
			p = realloc(buff, buff_length *= 2);
			if (p == NULL)
				cpio_errc(cpio, 1, ENOMEM,
				    "Line too long in %s", pathname);
			buff_end = p + (buff_end - buff);
			line_end = p + (line_end - buff);
			line_start = buff = p;
		}
	}
	/* At end-of-file, handle the final line. */
	if (line_end > line_start) {
		*line_end = '\0';
		if ((*process)(cpio, line_start) != 0)
			ret = -1;
	}
	free(buff);
	if (f != stdin)
		fclose(f);
	return (ret);
}

void
cpio_strmode(struct archive_entry *entry, char *bp)
{
	static const char *perms = "?rwxrwxrwx ";
	static const mode_t permbits[] =
	    { 0400, 0200, 0100, 0040, 0020, 0010, 0004, 0002, 0001 };
	mode_t mode;
	int i;

	/* Fill in a default string, then selectively override. */
	strcpy(bp, perms);

	mode = archive_entry_mode(entry);
	switch (mode & S_IFMT) {
	case S_IFREG:  bp[0] = '-'; break;
	case S_IFBLK:  bp[0] = 'b'; break;
	case S_IFCHR:  bp[0] = 'c'; break;
	case S_IFDIR:  bp[0] = 'd'; break;
	case S_IFLNK:  bp[0] = 'l'; break;
	case S_IFSOCK: bp[0] = 's'; break;
#ifdef S_IFIFO
	case S_IFIFO:  bp[0] = 'p'; break;
#endif
#ifdef S_IFWHT
	case S_IFWHT:  bp[0] = 'w'; break;
#endif
	}

	for (i = 0; i < 9; i++)
		if (!(mode & permbits[i]))
			bp[i+1] = '-';

	if (mode & S_ISUID) {
		if (mode & S_IXUSR) bp[3] = 's';
		else bp[3] = 'S';
	}
	if (mode & S_ISGID) {
		if (mode & S_IXGRP) bp[6] = 's';
		else bp[6] = 'S';
	}
	if (mode & S_ISVTX) {
		if (mode & S_IXOTH) bp[9] = 't';
		else bp[9] = 'T';
	}
	if (archive_entry_acl_count(entry, ARCHIVE_ENTRY_ACL_TYPE_ACCESS))
		bp[10] = '+';
}
