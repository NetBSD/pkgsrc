/*	$NetBSD: fileio-plain.c,v 1.2 2019/12/01 06:03:58 rin Exp $	*/

/*-
 * Copyright (c) 2011 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Matthias Scheler.
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

#define	FILEIO_INTERNAL	/**/

#include "fileio.h"

#include <stdlib.h>

static void
PlainCloseFunc(FileHandle *fh)
{
	int *fd_p = fh->fh_InstData;

	if (*fd_p >= 0)
		(void)close(*fd_p);
}

static ssize_t
PlainReadFunc(FileHandle *fh, void *buffer, size_t bytes)
{
	int *fd_p = fh->fh_InstData;
	
	return read(*fd_p, buffer, bytes);
}

FileHandle *
FileHandlePlain(int *fd_p)
{
	FileHandle  *fh;

	fh = FileHandleCreate(PlainCloseFunc, PlainReadFunc, sizeof(int));
	if (fh != NULL) {
		int *new_fd_p = fh->fh_InstData;

		*new_fd_p = *fd_p;
		*fd_p = -1;
	}

	return fh;
}
