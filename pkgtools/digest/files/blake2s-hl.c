/* $NetBSD: blake2s-hl.c,v 1.1 2021/09/28 13:05:08 nia Exp $	*/

/*
 * blake2s-hl.c
 * This code is derived from sha2hl.c, hence the following licence
 * reproduction.
 *
 * This code is not a verbatim copy, since some routines have been added,
 * and some bugs have been fixed.
 *
 * Version 1.0.0beta1
 *
 * Written by Aaron D. Gifford <me@aarongifford.com>
 *
 * Copyright 2000 Aaron D. Gifford.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) AND CONTRIBUTOR(S) ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) OR CONTRIBUTOR(S) BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "blake2s.h"

static const char blake2_hex_digits[] = "0123456789abcdef";

#ifndef MEMSET_BZERO
#define MEMSET_BZERO(p,l)	memset((p), 0, (l))
#endif

#ifndef _DIAGASSERT
#define _DIAGASSERT(cond)	assert(cond)
#endif

void
BLAKE2s_Init(struct blake2s *ctx)
{
	blake2s_init(ctx, BLAKE2S_MAX_DIGEST, NULL, 0);
}

void
BLAKE2s_Update(struct blake2s *ctx, const uint8_t *input, size_t len)
{
	blake2s_update(ctx, input, len);
}

char *
BLAKE2s_File(char *filename, char *buf)
{
	unsigned char	buffer[BUFSIZ * 20];
	struct blake2s	ctx;
	int		fd, num, oerrno;

	_DIAGASSERT(filename != NULL);
	/* XXX: buf may be NULL ? */

	BLAKE2s_Init(&ctx);

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);

	while ((num = read(fd, buffer, sizeof(buffer))) > 0)
		blake2s_update(&ctx, buffer, (size_t) num);

	oerrno = errno;
	close(fd);
	errno = oerrno;
	BLAKE2s_End(&ctx, buf);
	return (num < 0 ? 0 : buf);
}

char *
BLAKE2s_End(struct blake2s *ctx, char buffer[])
{
	unsigned char digest[BLAKE2S_MAX_DIGEST], *d = digest;
	unsigned char *ret;
	int i;

	assert(ctx != NULL);

	if ((ret = buffer) != NULL) {
		blake2s_final(ctx, digest);

		for (i = 0; i < BLAKE2S_MAX_DIGEST; i++) {
			*buffer++ = blake2_hex_digits[(*d & 0xf0) >> 4];
			*buffer++ = blake2_hex_digits[*d & 0x0f];
			d++;
		}
		*buffer = '\0';
	} else {
		(void)MEMSET_BZERO(ctx, sizeof(struct blake2s));
	}
	(void)MEMSET_BZERO(digest, BLAKE2S_MAX_DIGEST);
	return ret;
}
