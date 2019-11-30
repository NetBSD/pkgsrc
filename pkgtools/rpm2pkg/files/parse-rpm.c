/*	$NetBSD: parse-rpm.c,v 1.2 2019/11/30 23:31:30 rin Exp $	*/

/*-
 * Copyright (c) 2001-2019 The NetBSD Foundation, Inc.
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

#include "parse-rpm.h"

#include <sys/types.h>
#include <arpa/inet.h>

#include <inttypes.h>
#include <string.h>

/*
 * The following definitions are based on the documentation of the
 * RPM format which can be found here:
 *
 * http://www.rpm.org/max-rpm/s1-rpm-file-format-rpm-file-format.html
 */

/* Lead of an RPM archive. */
typedef struct RPMLead_s {
	uint8_t		magic[4];
	uint8_t		major, minor;
	int16_t		type;
	int16_t		archnum;
	int8_t		name[66];
	int16_t		osnum;
	uint16_t	signature_type;
	int8_t		reserved[16];
} RPMLead;

static const uint8_t RPMLeadMagic[] = { 0xed, 0xab, 0xee, 0xdb };

/* Header section of an RPM archive. */
typedef struct RPMHeader_s {
	uint8_t		magic[3];
	uint8_t		version;
	uint8_t		reserved[4];
	uint32_t	indexSize;
	uint32_t	dataSize;
} RPMHeader;

static const uint8_t RPMHeaderMagic[] = { 0x8e, 0xad, 0xe8 };

/* Magic bytes for "bzip2", "gzip", and "zstd" compressed files. */
static const unsigned char BZipMagic[] = { 'B', 'Z', 'h' };
static const unsigned char GZipMagic[] = { 0x1f, 0x8b, 0x08 };
static const unsigned char ZstdMagic[] = { 0x28, 0xb5, 0x2f, 0xfd };

/* Magic bytes for a cpio(1) archive. */
static const unsigned char CPIOMagic[] = {'0','7','0','7','0','1'};

/* Check whether we got an RPM file and find the data section. */
bool
IsRPMFile(int fd)
{
	RPMLead		rpmLead;
	bool		padding;
	RPMHeader	rpmHeader;

	/* Check for RPM lead. */
	if (read(fd, &rpmLead, sizeof(RPMLead)) != sizeof(RPMLead))
		return false;

	if (memcmp(rpmLead.magic, RPMLeadMagic, sizeof(RPMLeadMagic)) != 0)
		return false;

	/* We don't support very old RPMs. */
	if (rpmLead.major < 3)
		return false;

	/*
	 * The RPM file format has a horrible requirement for extra padding
	 * depending on what type of signature is used.
	 */
	padding = htons(rpmLead.signature_type) == 5;

	/* Skip over RPM header(s). */
	while (read(fd, &rpmHeader, sizeof(RPMHeader)) == sizeof(RPMHeader)) {
		uint32_t	indexSize, dataSize;
		off_t		offset;

		/* Did we find another header? */		
		if (memcmp(rpmHeader.magic, RPMHeaderMagic,
		    sizeof(RPMHeaderMagic)) != 0) {
			/* Nope, seek backwards and return. */
			return (lseek(fd, -(off_t)sizeof(RPMHeader),
			    SEEK_CUR) != -1);
		}

		/* Find out how large the header is ... */
		indexSize = htonl(rpmHeader.indexSize);
		dataSize = htonl(rpmHeader.dataSize);

		/* .. and skip over it. */
		offset = indexSize * 4 * sizeof(uint32_t) + dataSize;
		if (padding) {
			offset = ((offset + 7) / 8) * 8;
			padding = false;
		}
		if (lseek(fd, offset, SEEK_CUR) == -1)
			return false;
	}

	return false;
}

FileHandle *
OpenRPM(int *fd_p)
{
	unsigned char buffer[8];
	FileHandle *fh;

	/*
	 * Read enough bytes to identify the compression and seek back to
	 * the beginning of the data section.
	 */
	if (read(*fd_p, buffer, sizeof(buffer)) != sizeof(buffer) ||
	    lseek(*fd_p, -(off_t)sizeof(buffer), SEEK_CUR) == -1) {
		return NULL;
	}

	/* Determine the compression method. */
	if (memcmp(buffer, CPIOMagic, sizeof(CPIOMagic)) == 0) {
		/* uncompressed data */
		fh = FileHandlePlain(fd_p);		
	} else if (memcmp(buffer, BZipMagic, sizeof(BZipMagic)) == 0) {
		/* bzip2 archive */
		fh = FileHandleBZLib(fd_p);
	} else if (memcmp(buffer, GZipMagic, sizeof(GZipMagic)) == 0) {
		/* gzip archive */
		fh = FileHandleZLib(fd_p);
	} else if (memcmp(buffer, ZstdMagic, sizeof(ZstdMagic)) == 0) {
		/* zstd archive */
		fh = FileHandleZstd(fd_p);
	} else {
		/* lzma ... hopefully */
		fh = FileHandleLZMA(fd_p);
	}

	return fh;
}
