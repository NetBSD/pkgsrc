/*	$NetBSD: fileio-bzlib.c,v 1.2 2019/12/01 06:03:58 rin Exp $	*/

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

#include <bzlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	FILE	*id_File;
	int	id_bzerror;
	BZFILE	*id_BZFile;
} InstData;

static void
BZLibCloseFunc(FileHandle *fh)
{
	InstData *id;

	id = fh->fh_InstData;

	if (id->id_BZFile != NULL)
                (void)BZ2_bzReadClose(&id->id_bzerror, id->id_BZFile);

	if (id->id_File != NULL)
		(void)fclose(id->id_File);
}

static ssize_t
BZLibReadFunc(FileHandle *fh, void *buffer, size_t bytes)
{
	InstData *id;
	int rbytes;

	id = fh->fh_InstData;
	
	rbytes = BZ2_bzRead(&id->id_bzerror, id->id_BZFile, buffer, bytes);
	switch (id->id_bzerror) {
	case BZ_OK:
	case BZ_STREAM_END:
		return rbytes;

	default:
		return -1;
	}
}

FileHandle *
FileHandleBZLib(int *fd_p)
{
	FileHandle *fh;
	InstData *id;

	fh = FileHandleCreate(BZLibCloseFunc, BZLibReadFunc, sizeof(*id));
	if (fh == NULL)
		return NULL;
	id = fh->fh_InstData;

	if ((id->id_File = fdopen(*fd_p, "rb")) == NULL) {
		FileHandleClose(fh);
		return NULL;
	}
	*fd_p = -1;

	if ((id->id_BZFile = BZ2_bzReadOpen(&id->id_bzerror, id->id_File, 0, 0,
	    NULL, 0)) == NULL) {
		FileHandleClose(fh);
		return NULL;
	}

	return fh;
}
