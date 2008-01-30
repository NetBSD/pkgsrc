/* $NetBSD: read_file.c,v 1.4 2008/01/30 21:52:09 joerg Exp $ */

/*-
 * Copyright (c) 2007 Joerg Sonnenberger <joerg@NetBSD.org>.
 * All rights reserved.
 *
 * This code was developed as part of Google's Summer of Code 2007 program.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <nbcompat.h>

#include <nbcompat/stat.h>
#include <nbcompat/err.h>
#include <fcntl.h>
#include <nbcompat/limits.h>
#include <nbcompat/string.h>
#include <nbcompat/unistd.h>

#include "pbulk.h"

char *
read_from_file(int fd)
{
	struct stat sb;
	size_t input_len;
	ssize_t bytes_read;
	char *input;
	
	if (fstat(fd, &sb) == -1)
		err(1, "Cannot stat input");
	
	if ((sb.st_mode & S_IFMT) != S_IFREG)
		errx(1, "Input is not regular file");
	if (sb.st_size > SSIZE_MAX - 1)
		errx(1, "Input too large");

	input_len = (size_t)sb.st_size;
	input = xmalloc(input_len + 1);
	if ((bytes_read = read(fd, input, input_len)) == -1)
		err(1, "Failed to read input");
	if (bytes_read != sb.st_size)
		errx(1, "Unexpected short read");

	input[input_len] = '\0';
	if (strlen(input) != input_len)
		errx(1, "Invalid input (NUL character found)");

	return input;
}
