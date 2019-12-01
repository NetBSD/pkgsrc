/*	$NetBSD: fileio.c,v 1.2 2019/12/01 06:03:58 rin Exp $	*/

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

FileHandle *
FileHandleCreate(FileHandleCloseFunc close_func, FileHandleReadFunc read_func,
    size_t inst_size)
{
	FileHandle *fh;

	if ((fh = calloc(1, sizeof(*fh) + inst_size)) == NULL)
		return NULL;

	fh->fh_CloseFunc = close_func;
	fh->fh_ReadFunc = read_func;

	if (inst_size > 0)
		fh->fh_InstData = &fh[1];

	return fh;
}

void
FileHandleClose(FileHandle *fh)
{
	fh->fh_CloseFunc(fh);
	free(fh);
}

bool
FileHandleRead(FileHandle *fh, void *buffer, size_t bytes)
{
	char *ptr;

	ptr = buffer;
	while (bytes > 0) {
		ssize_t rbytes;

		rbytes = fh->fh_ReadFunc(fh, ptr, bytes);
		if (rbytes <= 0)
			break;

		ptr += rbytes;
		bytes -= rbytes;

		fh->fh_Pos += rbytes;
	}

	return (bytes == 0);
}

off_t
FileHandleGetPos(const FileHandle *fh)
{
	return fh->fh_Pos;
}
