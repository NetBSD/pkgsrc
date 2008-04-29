/* 	$NetBSD: getline.c,v 1.2 2008/04/29 05:46:09 martin Exp $ */
/*	$NetBSD: getline.c,v 1.2 2008/04/29 05:46:09 martin Exp $	*/

/*-
 * Copyright (c) 1997-2007 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Luke Mewburn.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,
 * NASA Ames Research Center.
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

#include <stdio.h>

/* Read a line from the FILE stream into buf/buflen using fgets(), so up
 * to buflen-1 chars will be read and the result will be NUL terminated.
 * If the line has a trailing newline it will be removed.
 * If the line is too long, excess characters will be read until
 * newline/EOF/error.
 * If EOF/error occurs or a too-long line is encountered and errormsg
 * isn't NULL, it will be changed to a description of the problem.
 * (The EOF message has a leading \n for cosmetic purposes).
 * Returns:
 *	>=0	length of line (excluding trailing newline) if all ok
 *	-1	error occurred
 *	-2	EOF encountered
 *	-3	line was too long
 */
int
getline(FILE *stream, char *buf, size_t buflen, const char **errormsg)
{
	int	rv, ch;
	size_t	len;

	if (fgets(buf, buflen, stream) == NULL) {
		if (feof(stream)) {	/* EOF */
			rv = -2;
			if (errormsg)
				*errormsg = "\nEOF received";
		} else  {		/* error */
			rv = -1;
			if (errormsg)
				*errormsg = "Error encountered";
		}
		clearerr(stream);
		return rv;
	}
	len = strlen(buf);
	if (buf[len-1] == '\n') {	/* clear any trailing newline */
		buf[--len] = '\0';
	} else if (len == buflen-1) {	/* line too long */
		while ((ch = getchar()) != '\n' && ch != EOF)
			continue;
		if (errormsg)
			*errormsg = "Input line is too long";
		clearerr(stream);
		return -3;
	}
	if (errormsg)
		*errormsg = NULL;
	return len;
}
