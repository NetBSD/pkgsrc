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
/*
The Keccak sponge function, designed by Guido Bertoni, Joan Daemen,
Michaël Peeters and Gilles Van Assche. For more information, feedback or
questions, please refer to our website: http://keccak.noekeon.org/

Implementation by the designers,
hereby denoted as "the implementer".

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/
*/
#ifndef _KeccakSponge_h_
#define _KeccakSponge_h_	20130813

#include <inttypes.h>

#define KECCAK_PERMUTATION_SIZE_BITS	1600
#define KECCAK_MAX_RATE_BITS		1536

#define KECCAK_NUM_ROUNDS		24
#define KECCAK_NUM_LANES		25

#if defined(__GNUC__)
#define ALIGN __attribute__ ((aligned(32)))
#elif defined(_MSC_VER)
#define ALIGN __declspec(align(32))
#else
#define ALIGN
#endif

ALIGN typedef struct KECCAK_CTX {
	ALIGN uint8_t	state[KECCAK_PERMUTATION_SIZE_BITS / 8];
	ALIGN uint8_t	dataQueue[KECCAK_MAX_RATE_BITS / 8];
	uint32_t	rate;
	uint32_t	capacity;
	uint32_t	bitsInQueue;
	uint32_t	fixedOutputLength;
	int32_t		squeezing;
	uint32_t	bitsAvailableForSqueezing;
	uint64_t	RoundConstants[KECCAK_NUM_ROUNDS];
	uint32_t	RhoOffsets[KECCAK_NUM_LANES];
} KECCAK_CTX;

typedef enum { SUCCESS = 0, FAIL = 1, BAD_HASHLEN = 2 } HashReturn;

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

HashReturn KECCAK_Init(KECCAK_CTX */*ctx*/, int /*hashbitlen*/);
HashReturn KECCAK_Update(KECCAK_CTX */*ctx*/, const uint8_t */*data*/, uint64_t /*databitlen*/);
HashReturn KECCAK_Final(KECCAK_CTX */*ctx*/, uint8_t */*hashval*/);

__END_DECLS

#endif
