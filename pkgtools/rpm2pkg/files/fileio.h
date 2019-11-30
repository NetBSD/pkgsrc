/*-
 * Copyright (c) 2011, 2019 The NetBSD Foundation, Inc.
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

#ifndef FILEIO_H
#define FILEIO_H

#include <stdbool.h>
#include <unistd.h>

typedef struct FileHandleStruct FileHandle;

extern void	FileHandleClose(FileHandle *);
extern bool	FileHandleRead(FileHandle *, void *, size_t);
extern off_t	FileHandleGetPos(const FileHandle *fh);

extern FileHandle *FileHandleBZLib(int *);
extern FileHandle *FileHandleLZMA(int *);
extern FileHandle *FileHandlePlain(int *);
extern FileHandle *FileHandleZLib(int *);
extern FileHandle *FileHandleZstd(int *);

#ifdef	FILEIO_INTERNAL

typedef void	(*FileHandleCloseFunc)(struct FileHandleStruct *);
typedef ssize_t	(*FileHandleReadFunc)(struct FileHandleStruct *, void *,size_t);

struct FileHandleStruct {
	FileHandleCloseFunc	fh_CloseFunc;
	FileHandleReadFunc	fh_ReadFunc;

	void			*fh_InstData;

	off_t			fh_Pos;
};

extern FileHandle *FileHandleCreate(FileHandleCloseFunc, FileHandleReadFunc,
    size_t);

#endif /* FILEIO_INTERNAL */

#endif /* !FILEIO_H */
