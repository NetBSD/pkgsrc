/*-
 * Copyright (c) 2015 Taylor R. Campbell
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef	BLAKE2S_H
#define	BLAKE2S_H

#include <stddef.h>
#include <stdint.h>

struct blake2s {
	uint8_t		b[64];	/* 64-byte buffer */
	uint32_t	h[8];	/* 32-byte state */
	uint64_t	c;	/* 64-bit input byte counter */
	uint8_t		nb;	/* number of bytes in buffer */
	uint8_t		dlen;	/* digest length */
};

#define	BLAKE2S_MAX_DIGEST	32
#define	BLAKE2S_MAX_KEY		32

void	blake2s_init(struct blake2s *, size_t, const void *, size_t);
void	blake2s_update(struct blake2s *, const void *, size_t);
void	blake2s_final(struct blake2s *, void *);
void	blake2s(void *, size_t, const void *, size_t, const void *, size_t);
int	blake2s_selftest(void);

void	BLAKE2s_Init(struct blake2s *ctx);
void	BLAKE2s_Update(struct blake2s *ctx, const uint8_t *, size_t);
char	*BLAKE2s_File(char *filename, char *buf);
char	*BLAKE2s_End(struct blake2s *ctx, char buffer[]);

#endif	/* BLAKE2S_H */
