/* $NetBSD: sha3hl.c,v 1.1 2016/03/03 22:11:07 agc Exp $	 */

/*
 * sha3hl.c
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
#include "sha3.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef _DIAGASSERT
#define _DIAGASSERT(cond)	assert(cond)
#endif

#ifndef MEMSET_BZERO
#define MEMSET_BZERO(p,l)	memset((p), 0, (l))
#endif

/*
 * Constant used by SHA3_224/256/384/512_End() functions for converting the
 * digest to a readable hexadecimal character string:
 */
static const char sha3_hex_digits[] = "0123456789abcdef";

char           *
SHA3_224_File(char *filename, char *buf)
{
	unsigned char          buffer[BUFSIZ * 20];
	SHA3_224_CTX      ctx;
	int             fd, num, oerrno;

	_DIAGASSERT(filename != NULL);
	/* XXX: buf may be NULL ? */

	SHA3_224_Init(&ctx);

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);

	while ((num = read(fd, buffer, sizeof(buffer))) > 0)
		SHA3_224_Update(&ctx, buffer, (size_t) num);

	oerrno = errno;
	close(fd);
	errno = oerrno;
	return (num < 0 ? 0 : SHA3_224_End(&ctx, buf));
}


char           *
SHA3_224_End(SHA3_224_CTX *ctx, char buffer[])
{
	unsigned char          digest[SHA3_224_DIGEST_LENGTH], *d = digest;
	unsigned char	       *ret;
	int             i;

	/* Sanity check: */
	assert(ctx != NULL);

	if ((ret = buffer) != NULL) {
		SHA3_224_Final(digest, ctx);

		for (i = 0; i < SHA3_224_DIGEST_LENGTH; i++) {
			*buffer++ = sha3_hex_digits[(*d & 0xf0) >> 4];
			*buffer++ = sha3_hex_digits[*d & 0x0f];
			d++;
		}
		*buffer = (char) 0;
	} else {
		(void) MEMSET_BZERO(ctx, sizeof(SHA3_224_CTX));
	}
	(void) MEMSET_BZERO(digest, SHA3_224_DIGEST_LENGTH);
	return ret;
}

char           *
SHA3_224_Data(const uint8_t * data, size_t len, unsigned char *digest)
{
	SHA3_224_CTX      ctx;

	SHA3_224_Init(&ctx);
	SHA3_224_Update(&ctx, data, len);
	return SHA3_224_End(&ctx, digest);
}

char           *
SHA3_256_File(char *filename, char *buf)
{
	unsigned char          buffer[BUFSIZ * 20];
	SHA3_256_CTX      ctx;
	int             fd, num, oerrno;

	_DIAGASSERT(filename != NULL);
	/* XXX: buf may be NULL ? */

	SHA3_256_Init(&ctx);

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);

	while ((num = read(fd, buffer, sizeof(buffer))) > 0)
		SHA3_256_Update(&ctx, buffer, (size_t) num);

	oerrno = errno;
	close(fd);
	errno = oerrno;
	return (num < 0 ? 0 : SHA3_256_End(&ctx, buf));
}


char           *
SHA3_256_End(SHA3_256_CTX *ctx, char buffer[])
{
	unsigned char          digest[SHA3_256_DIGEST_LENGTH], *d = digest;
	unsigned char	       *ret;
	int             i;

	/* Sanity check: */
	assert(ctx != NULL);

	if ((ret = buffer) != NULL) {
		SHA3_256_Final(digest, ctx);

		for (i = 0; i < SHA3_256_DIGEST_LENGTH; i++) {
			*buffer++ = sha3_hex_digits[(*d & 0xf0) >> 4];
			*buffer++ = sha3_hex_digits[*d & 0x0f];
			d++;
		}
		*buffer = (char) 0;
	} else {
		(void) MEMSET_BZERO(ctx, sizeof(SHA3_256_CTX));
	}
	(void) MEMSET_BZERO(digest, SHA3_256_DIGEST_LENGTH);
	return ret;
}

char           *
SHA3_256_Data(const uint8_t * data, size_t len, unsigned char *digest)
{
	SHA3_256_CTX      ctx;

	SHA3_256_Init(&ctx);
	SHA3_256_Update(&ctx, data, len);
	return SHA3_256_End(&ctx, digest);
}

char           *
SHA3_384_File(char *filename, char *buf)
{
	unsigned char          buffer[BUFSIZ * 20];
	SHA3_384_CTX      ctx;
	int             fd, num, oerrno;

	_DIAGASSERT(filename != NULL);
	/* XXX: buf may be NULL ? */

	SHA3_384_Init(&ctx);

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);

	while ((num = read(fd, buffer, sizeof(buffer))) > 0)
		SHA3_384_Update(&ctx, buffer, (size_t) num);

	oerrno = errno;
	close(fd);
	errno = oerrno;
	return (num < 0 ? 0 : SHA3_384_End(&ctx, buf));
}


char           *
SHA3_384_End(SHA3_384_CTX *ctx, char buffer[])
{
	unsigned char          digest[SHA3_384_DIGEST_LENGTH], *d = digest;
	unsigned char	       *ret;
	int             i;

	/* Sanity check: */
	assert(ctx != NULL);

	if ((ret = buffer) != NULL) {
		SHA3_384_Final(digest, ctx);

		for (i = 0; i < SHA3_384_DIGEST_LENGTH; i++) {
			*buffer++ = sha3_hex_digits[(*d & 0xf0) >> 4];
			*buffer++ = sha3_hex_digits[*d & 0x0f];
			d++;
		}
		*buffer = (char) 0;
	} else {
		(void) MEMSET_BZERO(ctx, sizeof(SHA3_384_CTX));
	}
	(void) MEMSET_BZERO(digest, SHA3_384_DIGEST_LENGTH);
	return ret;
}

char           *
SHA3_384_Data(const uint8_t * data, size_t len, unsigned char *digest)
{
	SHA3_384_CTX      ctx;

	SHA3_384_Init(&ctx);
	SHA3_384_Update(&ctx, data, len);
	return SHA3_384_End(&ctx, digest);
}

char           *
SHA3_512_File(char *filename, char *buf)
{
	unsigned char          buffer[BUFSIZ * 20];
	SHA3_512_CTX      ctx;
	int             fd, num, oerrno;

	_DIAGASSERT(filename != NULL);
	/* XXX: buf may be NULL ? */

	SHA3_512_Init(&ctx);

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);

	while ((num = read(fd, buffer, sizeof(buffer))) > 0)
		SHA3_512_Update(&ctx, buffer, (size_t) num);

	oerrno = errno;
	close(fd);
	errno = oerrno;
	return (num < 0 ? 0 : SHA3_512_End(&ctx, buf));
}


char           *
SHA3_512_End(SHA3_512_CTX *ctx, char buffer[])
{
	unsigned char          digest[SHA3_512_DIGEST_LENGTH], *d = digest;
	unsigned char	       *ret;
	int             i;

	/* Sanity check: */
	assert(ctx != NULL);

	if ((ret = buffer) != NULL) {
		SHA3_512_Final(digest, ctx);

		for (i = 0; i < SHA3_512_DIGEST_LENGTH; i++) {
			*buffer++ = sha3_hex_digits[(*d & 0xf0) >> 4];
			*buffer++ = sha3_hex_digits[*d & 0x0f];
			d++;
		}
		*buffer = (char) 0;
	} else {
		(void) MEMSET_BZERO(ctx, sizeof(SHA3_512_CTX));
	}
	(void) MEMSET_BZERO(digest, SHA3_512_DIGEST_LENGTH);
	return ret;
}

char           *
SHA3_512_Data(const uint8_t * data, size_t len, unsigned char *digest)
{
	SHA3_512_CTX      ctx;

	SHA3_512_Init(&ctx);
	SHA3_512_Update(&ctx, data, len);
	return SHA3_512_End(&ctx, digest);
}

