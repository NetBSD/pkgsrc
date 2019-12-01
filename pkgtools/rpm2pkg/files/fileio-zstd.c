/*	$NetBSD: fileio-zstd.c,v 1.3 2019/12/01 06:05:44 rin Exp $	*/
/*	NetBSD: fileio-bzlib.c,v 1.2 2019/12/01 06:03:58 rin Exp	*/

/*-
 * Copyright (c) 2011, 2019 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Matthias Scheler and Rin Okuyama.
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

#include <stdio.h>
#include <stdlib.h>
#include <zstd.h>

typedef struct {
	FILE		*id_File;
	ZSTD_DStream	*id_Stream;
	ZSTD_inBuffer	id_zib;
	void		*id_Buf;
	size_t		id_BufSize;
} InstData;

static void
ZstdCloseFunc(FileHandle *fh)
{
	InstData *id;

	id = fh->fh_InstData;

	if (id->id_Buf != NULL)
		free(id->id_Buf);

	if (id->id_Stream != NULL)
		(void)ZSTD_freeDStream(id->id_Stream);

	if (id->id_File != NULL)
		(void)fclose(id->id_File);
}

static ssize_t
ZstdReadFunc(FileHandle *fh, void *buffer, size_t bytes)
{
	InstData *id;
	ZSTD_outBuffer zob;
	size_t code;

	id = fh->fh_InstData;
	zob.dst = buffer;
	zob.size = bytes;
	zob.pos = 0;

	while (zob.pos < zob.size) {
		if (id->id_zib.pos >= id->id_zib.size) {
			id->id_zib.size = fread(id->id_Buf, 1, id->id_BufSize,
			    id->id_File);
			if (id->id_zib.size == 0)
				break;
			id->id_zib.src = id->id_Buf;
			id->id_zib.pos = 0;
		}
		code = ZSTD_decompressStream(id->id_Stream, &zob, &id->id_zib);
		if (ZSTD_isError(code))
			return -1;
	}

	return zob.pos;
}

FileHandle *
FileHandleZstd(int *fd_p)
{
	FileHandle *fh;
	InstData *id;

	fh = FileHandleCreate(ZstdCloseFunc, ZstdReadFunc, sizeof(*id));
	if (fh == NULL)
		return NULL;
	id = fh->fh_InstData;

	if ((id->id_File = fdopen(*fd_p, "rb")) == NULL) {
		FileHandleClose(fh);
		return NULL;
	}
	*fd_p = -1;

	id->id_Stream = ZSTD_createDStream();
	if (id->id_Stream == NULL ||
	    ZSTD_isError(ZSTD_initDStream(id->id_Stream)))
		return NULL;

	id->id_BufSize = ZSTD_DStreamOutSize();
	id->id_Buf = malloc(id->id_BufSize);
	if (id->id_Buf == NULL)
		return NULL;

	return fh;
}
