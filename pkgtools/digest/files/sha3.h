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

#ifndef	SHA3_H
#define	SHA3_H

#include <stddef.h>
#include <stdint.h>

struct sha3 {
	uint64_t A[25];
	unsigned nb;		/* number of bytes remaining to fill buffer */
};

typedef struct { struct sha3 C224; } SHA3_224_CTX;
typedef struct { struct sha3 C256; } SHA3_256_CTX;
typedef struct { struct sha3 C384; } SHA3_384_CTX;
typedef struct { struct sha3 C512; } SHA3_512_CTX;
typedef struct { struct sha3 C128; } SHAKE128_CTX;
typedef struct { struct sha3 C256; } SHAKE256_CTX;

#define	SHA3_224_DIGEST_LENGTH	28
#define	SHA3_256_DIGEST_LENGTH	32
#define	SHA3_384_DIGEST_LENGTH	48
#define	SHA3_512_DIGEST_LENGTH	64

#define	SHA3_224_DIGEST_STRING_LENGTH	((2 * SHA3_224_DIGEST_LENGTH) + 1)
#define	SHA3_256_DIGEST_STRING_LENGTH	((2 * SHA3_256_DIGEST_LENGTH) + 1)
#define	SHA3_384_DIGEST_STRING_LENGTH	((2 * SHA3_384_DIGEST_LENGTH) + 1)
#define	SHA3_512_DIGEST_STRING_LENGTH	((2 * SHA3_512_DIGEST_LENGTH) + 1)

#ifdef SHA3_PROTECT_NAMESPACE
#define	SHA3_224_Init	digest_SHA3_224_Init
#define	SHA3_224_Update	digest_SHA3_224_Update
#define	SHA3_224_Final	digest_SHA3_224_Final
#define	SHA3_224_End	digest_SHA3_224_End
#define	SHA3_224_Data	digest_SHA3_224_Data
#define	SHA3_224_File	digest_SHA3_224_File

#define	SHA3_256_Init	digest_SHA3_256_Init
#define	SHA3_256_Update	digest_SHA3_256_Update
#define	SHA3_256_Final	digest_SHA3_256_Final
#define	SHA3_256_End	digest_SHA3_256_End
#define	SHA3_256_Data	digest_SHA3_256_Data
#define	SHA3_256_File	digest_SHA3_256_File

#define	SHA3_384_Init	digest_SHA3_384_Init
#define	SHA3_384_Update	digest_SHA3_384_Update
#define	SHA3_384_Final	digest_SHA3_384_Final
#define	SHA3_384_End	digest_SHA3_384_End
#define	SHA3_384_Data	digest_SHA3_384_Data
#define	SHA3_384_File	digest_SHA3_384_File

#define	SHA3_512_Init	digest_SHA3_512_Init
#define	SHA3_512_Update	digest_SHA3_512_Update
#define	SHA3_512_Final	digest_SHA3_512_Final
#define	SHA3_512_End	digest_SHA3_512_End
#define	SHA3_512_Data	digest_SHA3_512_Data
#define	SHA3_512_File	digest_SHA3_512_File
#endif /* SHA3_PROTECT_NAMESPACE */

#ifndef __BEGIN_DECLS
#  if defined(__cplusplus)
#  define __BEGIN_DECLS           extern "C" {
#  define __END_DECLS             }
#  else
#  define __BEGIN_DECLS
#  define __END_DECLS
#  endif
#endif

__BEGIN_DECLS

void	SHA3_224_Init(SHA3_224_CTX *);
void	SHA3_224_Update(SHA3_224_CTX *, const uint8_t *, size_t);
void	SHA3_224_Final(uint8_t[SHA3_224_DIGEST_LENGTH], SHA3_224_CTX *);

void	SHA3_256_Init(SHA3_256_CTX *);
void	SHA3_256_Update(SHA3_256_CTX *, const uint8_t *, size_t);
void	SHA3_256_Final(uint8_t[SHA3_256_DIGEST_LENGTH], SHA3_256_CTX *);

void	SHA3_384_Init(SHA3_384_CTX *);
void	SHA3_384_Update(SHA3_384_CTX *, const uint8_t *, size_t);
void	SHA3_384_Final(uint8_t[SHA3_384_DIGEST_LENGTH], SHA3_384_CTX *);

void	SHA3_512_Init(SHA3_512_CTX *);
void	SHA3_512_Update(SHA3_512_CTX *, const uint8_t *, size_t);
void	SHA3_512_Final(uint8_t[SHA3_512_DIGEST_LENGTH], SHA3_512_CTX *);

void	SHAKE128_Init(SHAKE128_CTX *);
void	SHAKE128_Update(SHAKE128_CTX *, const uint8_t *, size_t);
void	SHAKE128_Final(uint8_t *, size_t, SHAKE128_CTX *);

void	SHAKE256_Init(SHAKE256_CTX *);
void	SHAKE256_Update(SHAKE256_CTX *, const uint8_t *, size_t);
void	SHAKE256_Final(uint8_t *, size_t, SHAKE256_CTX *);

int	SHA3_Selftest(void);

char *SHA3_224_End(SHA3_224_CTX*, char[SHA3_224_DIGEST_STRING_LENGTH]);
char *SHA3_224_Data(const uint8_t*, size_t, unsigned char *);
char *SHA3_224_File(char *, char *);

char *SHA3_256_End(SHA3_256_CTX*, char[SHA3_256_DIGEST_STRING_LENGTH]);
char *SHA3_256_Data(const uint8_t*, size_t, unsigned char *);
char *SHA3_256_File(char *, char *);

char *SHA3_384_End(SHA3_384_CTX*, char[SHA3_384_DIGEST_STRING_LENGTH]);
char *SHA3_384_Data(const uint8_t*, size_t, unsigned char *);
char *SHA3_384_File(char *, char *);

char *SHA3_512_End(SHA3_512_CTX*, char[SHA3_512_DIGEST_STRING_LENGTH]);
char *SHA3_512_Data(const uint8_t*, size_t, unsigned char *);
char *SHA3_512_File(char *, char *);

__END_DECLS

#endif	/* SHA3_H */
