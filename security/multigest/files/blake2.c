/*-
 * Copyright (c) 2013 Alistair Crooks <agc@NetBSD.org>
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "blake2.h"

#define BLAKE2B_SALTBYTES  16
#define BLAKE2B_PERSONALBYTES 16
#define BLAKE2B_OUTBYTES   64
#define BLAKE2B_KEYBYTES   64

typedef struct __blake2b_param {
	uint8_t  digest_length; // 1
	uint8_t  key_length;    // 2
	uint8_t  fanout;        // 3
	uint8_t  depth;         // 4
	uint32_t leaf_length;   // 8
	uint64_t node_offset;   // 16
	uint8_t  node_depth;    // 17
	uint8_t  inner_length;  // 18
	uint8_t  reserved[14];  // 32
	uint8_t  salt[BLAKE2B_SALTBYTES]; // 48
	uint8_t  personal[BLAKE2B_PERSONALBYTES];  // 64
} blake2b_param;

static const uint64_t blake2b_IV[8] = {
	0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL,
	0x3c6ef372fe94f82bULL, 0xa54ff53a5f1d36f1ULL,
	0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL,
	0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL
};

static const uint8_t blake2b_sigma[12][16] = {
	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
	{ 14, 10,  4,  8,  9, 15, 13,  6,  1, 12,  0,  2, 11,  7,  5,  3 },
	{ 11,  8, 12,  0,  5,  2, 15, 13, 10, 14,  3,  6,  7,  1,  9,  4 },
	{  7,  9,  3,  1, 13, 12, 11, 14,  2,  6,  5, 10,  4,  0, 15,  8 },
	{  9,  0,  5,  7,  2,  4, 10, 15, 14,  1, 11, 12,  6,  8,  3, 13 },
	{  2, 12,  6, 10,  0, 11,  8,  3,  4, 13,  7,  5, 15, 14,  1,  9 },
	{ 12,  5,  1, 15, 14, 13,  4, 10,  0,  7,  6,  3,  9,  2,  8, 11 },
	{ 13, 11,  7, 14, 12,  1,  3,  9,  5,  0, 15,  4,  8,  6,  2, 10 },
	{  6, 15, 14,  9, 11,  3,  0,  8, 12,  2, 13,  7,  1,  4, 10,  5 },
	{ 10,  2,  8,  4,  7,  6,  1,  5, 15, 11,  9, 14,  3, 12, 13 , 0 },
	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
	{ 14, 10,  4,  8,  9, 15, 13,  6,  1, 12,  0,  2, 11,  7,  5,  3 }
};

/* prevents compiler optimizing out memset() */
static inline void secure_zero_memory(void *v, size_t n)
{
	volatile uint8_t *p = (volatile uint8_t *)v;

	while (n--) {
		*p++ = 0;
	}
}


static inline uint64_t
rotr64(const uint64_t w, const unsigned c)
{
	return (w >> c) | (w << (64 - c));
}


static inline uint64_t
load64(const void *src)
{ 
	const uint8_t	*p = (const uint8_t *)src;
	uint64_t	 w;
	int		 indian = 1;

	if (*(char *)(void *)&indian) {
		return *(const uint64_t *)(src);
	}
	w = *p++;
	w |= (uint64_t)(*p++) <<  8;
	w |= (uint64_t)(*p++) << 16;
	w |= (uint64_t)(*p++) << 24;
	w |= (uint64_t)(*p++) << 32;
	w |= (uint64_t)(*p++) << 40;
	w |= (uint64_t)(*p++) << 48;
	w |= (uint64_t)(*p++) << 56;
	return w;
}

static inline void
store32(void *dst, uint32_t w)
{
	uint8_t		*p = (uint8_t *)dst;
	int		 indian = 1;

	if (*(char *)(void *)&indian) {
		*(uint32_t *)(dst) = w;
	}
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w;
}

static inline void
store64(void *dst, uint64_t w)
{
	uint8_t		*p = (uint8_t *)dst;
	int		 indian = 1;

	if (*(char *)(void *)&indian) {
		*(uint64_t *)(dst) = w;
	}
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w; w >>= 8;
	*p++ = (uint8_t)w;
}

static inline int
blake2b_set_lastnode(BLAKE2_CTX *S)
{
	S->f[1] = ~0ULL;
	return 0;
}

static inline int
blake2b_clear_lastnode(BLAKE2_CTX *S)
{
	S->f[1] = 0ULL;
	return 0;
}

/* Some helper functions, not necessarily useful */
static inline int
blake2b_set_lastblock(BLAKE2_CTX *S)
{
	if (S->last_node) {
		blake2b_set_lastnode(S);
	}
	S->f[0] = ~0ULL;
	return 0;
}

static inline int
blake2b_clear_lastblock(BLAKE2_CTX *S)
{
	if (S->last_node) {
		blake2b_clear_lastnode(S);
	}
	S->f[0] = 0ULL;
	return 0;
}

static inline int
blake2b_increment_counter(BLAKE2_CTX *S, const uint64_t inc)
{
	S->t[0] += inc;
	S->t[1] += (S->t[0] < inc);
	return 0;
}



/* Parameter-related functions */
static inline int
blake2b_param_set_digest_length(blake2b_param *P, const uint8_t digest_length)
{
	P->digest_length = digest_length;
	return 0;
}

static inline int
blake2b_param_set_fanout(blake2b_param *P, const uint8_t fanout)
{
	P->fanout = fanout;
	return 0;
}

static inline int
blake2b_param_set_max_depth(blake2b_param *P, const uint8_t depth)
{
	P->depth = depth;
	return 0;
}

static inline int
blake2b_param_set_leaf_length(blake2b_param *P, const uint32_t leaf_length)
{
	store32(&P->leaf_length, leaf_length);
	return 0;
}

static inline int
blake2b_param_set_node_offset(blake2b_param *P, const uint64_t node_offset)
{
	store64(&P->node_offset, node_offset);
	return 0;
}

static inline int
blake2b_param_set_node_depth(blake2b_param *P, const uint8_t node_depth)
{
	P->node_depth = node_depth;
	return 0;
}

static inline int
blake2b_param_set_inner_length(blake2b_param *P, const uint8_t inner_length)
{
	P->inner_length = inner_length;
	return 0;
}

static inline int
blake2b_param_set_salt(blake2b_param *P, const uint8_t salt[BLAKE2B_SALTBYTES])
{
	memcpy(P->salt, salt, BLAKE2B_SALTBYTES);
	return 0;
}

static inline int
blake2b_param_set_personal(blake2b_param *P, const uint8_t personal[BLAKE2B_PERSONALBYTES])
{
	memcpy(P->personal, personal, BLAKE2B_PERSONALBYTES);
	return 0;
}

static inline int
blake2b_init0(BLAKE2_CTX *S)
{
	int	i;

	memset(S, 0, sizeof(*S));
	for (i = 0; i < 8; ++i) {
		S->h[i] = blake2b_IV[i];
	}
	return 0;
}

/* init xors IV with input parameter block */
static int
blake2b_init_param(BLAKE2_CTX *S, const blake2b_param *P)
{
	const uint8_t *p;
	size_t		i;

	blake2b_init0(S);
	p = (const uint8_t *)(const void *)(P);
	/* IV XOR ParamBlock */
	for (i = 0; i < 8; ++i) {
		S->h[i] ^= load64(p + sizeof(S->h[i]) * i);
	}
	return 0;
}

int
blake2b_init(BLAKE2_CTX *S, const uint8_t outlen)
{
	blake2b_param	P;

	if ((!outlen) || (outlen > BLAKE2B_OUTBYTES)) {
		return -1;
	}
	memset(&P, 0x0, sizeof(P));
	P.digest_length = outlen;
	P.key_length    = 0;
	P.fanout        = 1;
	P.depth         = 1;
	store32(&P.leaf_length, 0);
	store64(&P.node_offset, 0);
	P.node_depth    = 0;
	P.inner_length  = 0;
	memset(P.reserved, 0, sizeof(P.reserved));
	memset(P.salt,     0, sizeof(P.salt));
	memset(P.personal, 0, sizeof(P.personal));
	return blake2b_init_param(S, &P);
}


static int
blake2b_compress(BLAKE2_CTX *S, const uint8_t block[BLAKE2B_BLOCKBYTES])
{
	uint64_t m[16];
	uint64_t v[16];
	int i;

	for (i = 0; i < 16; ++i) {
		m[i] = load64(block + i * sizeof(m[i]));
	}
	for (i = 0; i < 8; ++i) {
		v[i] = S->h[i];
	}
	v[8] = blake2b_IV[0];
	v[9] = blake2b_IV[1];
	v[10] = blake2b_IV[2];
	v[11] = blake2b_IV[3];
	v[12] = S->t[0] ^ blake2b_IV[4];
	v[13] = S->t[1] ^ blake2b_IV[5];
	v[14] = S->f[0] ^ blake2b_IV[6];
	v[15] = S->f[1] ^ blake2b_IV[7];
#define G(r,i,a,b,c,d) do {						\
	a = a + b + m[blake2b_sigma[r][i + i]];				\
	d = rotr64(d ^ a, 32);						\
	c = c + d;							\
	b = rotr64(b ^ c, 24);						\
	a = a + b + m[blake2b_sigma[r][i + i + 1]];			\
	d = rotr64(d ^ a, 16);						\
	c = c + d;							\
	b = rotr64(b ^ c, 63);						\
} while(/*CONSTCOND*/0)
#define ROUND(r) do {							\
	G(r,0,v[0],v[4],v[8],v[12]);					\
	G(r,1,v[1],v[5],v[9],v[13]);					\
	G(r,2,v[2],v[6],v[10],v[14]);					\
	G(r,3,v[3],v[7],v[11],v[15]);					\
	G(r,4,v[0],v[5],v[10],v[15]);					\
	G(r,5,v[1],v[6],v[11],v[12]);					\
	G(r,6,v[2],v[7],v[8],v[13]);					\
	G(r,7,v[3],v[4],v[9],v[14]);					\
} while(/*CONSTCOND*/0)
	ROUND(0);
	ROUND(1);
	ROUND(2);
	ROUND(3);
	ROUND(4);
	ROUND(5);
	ROUND(6);
	ROUND(7);
	ROUND(8);
	ROUND(9);
	ROUND(10);
	ROUND(11);
	for (i = 0; i < 8; ++i) {
		S->h[i] = S->h[i] ^ v[i] ^ v[i + 8];
	}
#undef G
#undef ROUND
	return 0;
}

/* inlen now in bytes */
int
blake2b_update(BLAKE2_CTX *S, const uint8_t *in, uint64_t inlen)
{
	while (inlen > 0) {
		size_t left = S->buflen;
		size_t fill = 2 * BLAKE2B_BLOCKBYTES - left;

		if (inlen > fill) {
			memcpy(S->buf + left, in, fill); // Fill buffer
			S->buflen += fill;
			blake2b_increment_counter(S, BLAKE2B_BLOCKBYTES);
			blake2b_compress(S, S->buf); // Compress
			memcpy(S->buf, S->buf + BLAKE2B_BLOCKBYTES, BLAKE2B_BLOCKBYTES); // Shift buffer left
			S->buflen -= BLAKE2B_BLOCKBYTES;
			in += fill;
			inlen -= fill;
		} else {
			// inlen <= fill
			memcpy(S->buf + left, in, inlen);
			S->buflen += inlen; // Be lazy, do not compress
			in += inlen;
			inlen -= inlen;
		}
	}

	return 0;
}

/* Is this correct? */
int
blake2b_final(BLAKE2_CTX *S, uint8_t *out, uint8_t outlen)
{
	uint8_t buffer[BLAKE2B_OUTBYTES];
	int	i;

	if (S->buflen > BLAKE2B_BLOCKBYTES) {
		blake2b_increment_counter(S, BLAKE2B_BLOCKBYTES);
		blake2b_compress(S, S->buf);
		S->buflen -= BLAKE2B_BLOCKBYTES;
		memcpy(S->buf, S->buf + BLAKE2B_BLOCKBYTES, S->buflen);
	}
	blake2b_increment_counter(S, S->buflen);
	blake2b_set_lastblock(S);
	memset(S->buf + S->buflen, 0, 2 * BLAKE2B_BLOCKBYTES - S->buflen); /* Padding */
	blake2b_compress(S, S->buf);
	for (i = 0; i < 8; ++i) {
		/* Output full hash to temp buffer */ 
		store64(buffer + sizeof(S->h[i]) * i, S->h[i]);
	}
	memcpy(out, buffer, outlen);
	return 0;
}
