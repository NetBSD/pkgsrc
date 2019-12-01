/*	$NetBSD: fileio-lzma.c,v 1.2 2019/12/01 06:03:58 rin Exp $	*/

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

#include <inttypes.h>
#include <lzma.h>

typedef struct {
	lzma_stream	id_Stream;
	int		id_FD;
	size_t		id_Chunk;
	uint8_t		id_Buffer[1 << 16];
} InstData;

static void
LZMACloseFunc(FileHandle *fh)
{
	InstData *id;

	id = fh->fh_InstData;
	if (id != NULL) {
		lzma_end(&id->id_Stream);

		if (id->id_FD >= 0)
			(void)close(id->id_FD);

		fh->fh_InstData = NULL;
	}
}

static ssize_t
LZMAReadFunc(FileHandle *fh, void *buffer, size_t bytes)
{
	InstData *id;
	lzma_stream *stream;
	ssize_t rbytes;
	lzma_ret ret;

	id = fh->fh_InstData;
	if (id == NULL)
		return 0;

	stream = &id->id_Stream;
	if (stream->avail_in == 0 && id->id_FD >= 0) {
		rbytes = read(id->id_FD, id->id_Buffer, id->id_Chunk);
		if (rbytes < 0) {
			LZMACloseFunc(fh);
			return rbytes;
		}

		if (rbytes > 0) {
			stream->next_in = id->id_Buffer;
			stream->avail_in = rbytes;

			id->id_Chunk = sizeof(id->id_Buffer);
		} else {
			(void)close(id->id_FD);
			id->id_FD = -1;
		}
	}

	stream->next_out = buffer;
	stream->avail_out = bytes;
	ret = lzma_code(stream,
	    (stream->avail_in > 0) ? LZMA_RUN : LZMA_FINISH);

	rbytes = (ret == LZMA_OK || ret == LZMA_STREAM_END) ?
	    (ssize_t)(bytes - stream->avail_out) : -1;

	if (ret != LZMA_OK)
		LZMACloseFunc(fh);

	return rbytes;
}

FileHandle *
FileHandleLZMA(int *fd_p)
{
	FileHandle *fh;
	InstData *id;
	off_t offset;

	fh = FileHandleCreate(LZMACloseFunc, LZMAReadFunc, sizeof(*id));
	if (fh == NULL)
		return NULL;
	id = fh->fh_InstData;

	if (lzma_auto_decoder(&id->id_Stream, 1U << 30,
	    LZMA_CONCATENATED) != LZMA_OK) {
		fh->fh_InstData = NULL;
		FileHandleClose(fh);
		return NULL;
	}
	id->id_FD = *fd_p;
	*fd_p = -1;

	id->id_Chunk = sizeof(id->id_Buffer);
	offset = lseek(id->id_FD, 0, SEEK_CUR);
	if (offset != -1) {
		id->id_Chunk = sizeof(id->id_Buffer) -
		    (size_t)offset % sizeof(id->id_Buffer);
	}

	return fh;
}
