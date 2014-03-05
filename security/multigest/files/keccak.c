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

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keccak.h"

static void
fromBytesToWords(uint64_t *stateAsWords, const uint8_t *state)
{
	unsigned int i, j;

	for (i = 0; i < (KECCAK_PERMUTATION_SIZE_BITS / 64); i++) {
		stateAsWords[i] = 0;
		for (j = 0; j < (64/8); j++) {
			stateAsWords[i] |= (uint64_t)(state[i*(64/8)+j]) << (8*j);
		}
	}
}

static void
fromWordsToBytes(uint8_t *state, const uint64_t *stateAsWords)
{
	unsigned int i, j;

	for (i = 0; i < (KECCAK_PERMUTATION_SIZE_BITS / 64); i++) {
		for (j = 0; j < (64/8); j++) {
			state[i*(64/8)+j] = (uint8_t)(stateAsWords[i] >> (8*j)) & 0xFF;
		}
	}
}

#define INDEX(x, y) (((x)%5)+5*((y)%5))
#define ROL64(a, offset) (/*CONSTCOND*/(offset != 0) ? ((((uint64_t)a) << offset) ^ (((uint64_t)a) >> (64-offset))) : a)

static inline void
theta(uint64_t *A)
{
	unsigned int x, y;
	uint64_t C[5], D[5];

	for (x = 0; x < 5; x++) {
		C[x] = 0; 
		for (y = 0; y < 5; y++) {
			C[x] ^= A[INDEX(x, y)];
		}
	}
	for (x = 0; x < 5; x++) {
		D[x] = ROL64(C[(x+1)%5], 1) ^ C[(x+4)%5];
	}
	for (x = 0; x < 5; x++) {
		for (y = 0; y < 5; y++) {
			A[INDEX(x, y)] ^= D[x];
		}
	}
}

static inline void
rho(KECCAK_CTX *ctx, uint64_t *A)
{
	unsigned int x, y;

	for (x = 0; x < 5; x++) {
		for (y = 0; y < 5; y++) {
			A[INDEX(x, y)] = ROL64(A[INDEX(x, y)], ctx->RhoOffsets[INDEX(x, y)]);
		}
	}
}

static inline void
pi(uint64_t *A)
{
	unsigned int x, y;
	uint64_t tempA[25];

	for (x = 0; x < 5; x++) {
		for (y = 0; y < 5; y++) {
			tempA[INDEX(x, y)] = A[INDEX(x, y)];
		}
	}
	for (x = 0; x < 5; x++) {
		for (y = 0; y < 5; y++) {
			A[INDEX(0*x+1*y, 2*x+3*y)] = tempA[INDEX(x, y)];
		}
	}
}

static inline void
chi(uint64_t *A)
{
	unsigned int	x, y;
	uint64_t	C[5];

	for (y = 0; y < 5; y++) { 
		for (x = 0; x < 5; x++) {
			C[x] = A[INDEX(x, y)] ^ ((~A[INDEX(x+1, y)]) & A[INDEX(x+2, y)]);
		}
		for (x = 0; x < 5; x++) {
			A[INDEX(x, y)] = C[x];
		}
	}
}

static inline void
iota(KECCAK_CTX *ctx, uint64_t *A, unsigned int indexRound)
{
	A[INDEX(0, 0)] ^= ctx->RoundConstants[indexRound];
}

static inline void
KeccakPermutationOnWords(KECCAK_CTX *ctx, uint64_t *st)
{
	unsigned int	i;

	for (i = 0; i < KECCAK_NUM_ROUNDS; i++) {
		theta(st);
		rho(ctx, st);
		pi(st);
		chi(st);
		iota(ctx, st, i);
	}
}

static void
keccak_permutation(KECCAK_CTX *ctx)
{
	const int	indian = 1;
	uint64_t	stateAsWords[KECCAK_PERMUTATION_SIZE_BITS/64];

	if (*(const char *)(const void *)&indian) {
		/* little endian */
		KeccakPermutationOnWords(ctx, (uint64_t*)(void *)ctx->state);
	} else {
		fromBytesToWords(stateAsWords, ctx->state);
		KeccakPermutationOnWords(ctx, stateAsWords);
		fromWordsToBytes(ctx->state, stateAsWords);
	}
}

static void
KeccakPermutationAfterXor(KECCAK_CTX *ctx, uint8_t *state, const uint8_t *data, unsigned int dataLengthInBytes)
{
	unsigned int	i;

	for (i = 0; i < dataLengthInBytes; i++) {
		state[i] ^= data[i];
	}
	keccak_permutation(ctx);
}

static int
LFSR86540(uint8_t *LFSR)
{
	int	result = ((*LFSR) & 0x01) != 0;

	if (((*LFSR) & 0x80) != 0) {
		/* Primitive polynomial over GF(2): x^8+x^6+x^5+x^4+1 */
		(*LFSR) = ((*LFSR) << 1) ^ 0x71;
	} else {
		(*LFSR) = (*LFSR) << 1;
	}
	return result;
}

static void
keccak_initialise_RoundConstants(KECCAK_CTX *ctx)
{
	uint8_t		LFSRstate = 0x01;
	unsigned int	i, j, bitPosition;

	for (i = 0; i < KECCAK_NUM_ROUNDS; i++) {
		ctx->RoundConstants[i] = 0;
		for (j = 0; j < 7; j++) {
			bitPosition = (1<<j)-1; /*2^j-1 */
			if (LFSR86540(&LFSRstate)) {
				ctx->RoundConstants[i] ^= (uint64_t)1<<bitPosition;
			}
		}
	}
}

static void
keccak_initialise_RhoOffsets(KECCAK_CTX *ctx)
{
	unsigned int	x, y, t, newX, newY;

	ctx->RhoOffsets[INDEX(0, 0)] = 0;
	x = 1;
	y = 0;
	for (t = 0; t < 24; t++) {
		ctx->RhoOffsets[INDEX(x, y)] = ((t+1)*(t+2)/2) % 64;
		newX = (0*x+1*y) % 5;
		newY = (2*x+3*y) % 5;
		x = newX;
		y = newY;
	}
}

static int
init_sponge(KECCAK_CTX *ctx, unsigned int rate, unsigned int capacity)
{
	if (rate+capacity != 1600) {
		return 1;
	}
	if ((rate == 0) || (rate >= 1600) || ((rate % 64) != 0)) {
		return 1;
	}
	keccak_initialise_RoundConstants(ctx);
	keccak_initialise_RhoOffsets(ctx);
	ctx->rate = rate;
	ctx->capacity = capacity;
	ctx->fixedOutputLength = 0;
	memset(ctx->state, 0x0, sizeof(ctx->state));
	memset(ctx->dataQueue, 0x0, sizeof(ctx->dataQueue));
	ctx->bitsInQueue = 0;
	ctx->squeezing = 0;
	ctx->bitsAvailableForSqueezing = 0;
	return 0;
}

static inline void
absorb_queue(KECCAK_CTX *ctx)
{
	/* state->bitsInQueue is assumed to be equal to state->rate */
	KeccakPermutationAfterXor(ctx, ctx->state, ctx->dataQueue, ctx->rate / 8);
	ctx->bitsInQueue = 0;
}

static int
absorb(KECCAK_CTX *ctx, const uint8_t *data, uint64_t databitlen)
{
	uint64_t i, j, wholeBlocks;
	unsigned int partialBlock, partialByte;
	const uint8_t *curData;

	if ((ctx->bitsInQueue % 8) != 0) {
		return 1; /* Only the last call may contain a partial byte */
	}
	if (ctx->squeezing) {
		return 1; /* Too late for additional input */
	}
	for (i = 0; i < databitlen ; ) {
		if ((ctx->bitsInQueue == 0) && (databitlen >= ctx->rate) && (i <= (databitlen-ctx->rate))) {
			wholeBlocks = (databitlen-i)/ctx->rate;
			curData = &data[(long)i/8];
			for (j=0; j<wholeBlocks; j++, curData+=ctx->rate/8) {
				KeccakPermutationAfterXor(ctx, ctx->state, curData, ctx->rate / 8);
			}
			i += wholeBlocks*ctx->rate;
		} else {
			partialBlock = (unsigned int)(databitlen - i);
			if (partialBlock+ctx->bitsInQueue > ctx->rate) {
				partialBlock = ctx->rate-ctx->bitsInQueue;
			}
			partialByte = partialBlock % 8;
			partialBlock -= partialByte;
			memcpy(ctx->dataQueue+ctx->bitsInQueue/8, &data[(unsigned long)i/8], partialBlock/8);
			ctx->bitsInQueue += partialBlock;
			i += partialBlock;
			if (ctx->bitsInQueue == ctx->rate) {
				absorb_queue(ctx);
			}
			if (partialByte > 0) {
				uint8_t mask = (1 << partialByte)-1;
				ctx->dataQueue[ctx->bitsInQueue/8] = data[(unsigned long)i/8] & mask;
				ctx->bitsInQueue += partialByte;
				i += partialByte;
			}
		}
	}
	return 0;
}

static void
PadAndSwitchToSqueezingPhase(KECCAK_CTX *ctx)
{
	/* Note: the bits are numbered from 0=LSB to 7=MSB */
	if (ctx->bitsInQueue + 1 == ctx->rate) {
		ctx->dataQueue[ctx->bitsInQueue/8 ] |= 1 << (ctx->bitsInQueue % 8);
		absorb_queue(ctx);
		memset(ctx->dataQueue, 0, ctx->rate/8);
	} else {
		memset(ctx->dataQueue + (ctx->bitsInQueue+7)/8, 0, ctx->rate/8 - (ctx->bitsInQueue+7)/8);
		ctx->dataQueue[ctx->bitsInQueue/8 ] |= 1 << (ctx->bitsInQueue % 8);
	}
	ctx->dataQueue[(ctx->rate-1)/8] |= 1 << ((ctx->rate-1) % 8);
	absorb_queue(ctx);
	memcpy(ctx->dataQueue, ctx->state, ctx->rate/8);
	ctx->bitsAvailableForSqueezing = ctx->rate;
	ctx->squeezing = 1;
}

static int
squeeze(KECCAK_CTX *ctx, uint8_t *output, uint64_t outputLength)
{
	uint64_t i;
	unsigned int partialBlock;

	if (!ctx->squeezing) {
		PadAndSwitchToSqueezingPhase(ctx);
	}
	if ((outputLength % 8) != 0) {
		return 1; /* Only multiple of 8 bits are allowed, truncation can be done at user level */
	}
	for (i = 0; i < outputLength ; i += partialBlock) {
		if (ctx->bitsAvailableForSqueezing == 0) {
			keccak_permutation(ctx);
			memcpy(ctx->dataQueue, ctx->state, ctx->rate/8);
			ctx->bitsAvailableForSqueezing = ctx->rate;
		}
		partialBlock = ctx->bitsAvailableForSqueezing;
		if ((uint64_t)partialBlock > outputLength - i) {
			partialBlock = (unsigned int)(outputLength - i);
		}
		memcpy(&output[(unsigned long)i/8],
			ctx->dataQueue+(ctx->rate-ctx->bitsAvailableForSqueezing)/8,
			partialBlock/8);
		ctx->bitsAvailableForSqueezing -= partialBlock;
	}
	return 0;
}

/***************************************************************/

HashReturn
KECCAK_Init(KECCAK_CTX *ctx, int hashbitlen)
{
	switch(hashbitlen) {
	case 0: /* Default parameters, arbitrary length output */
		init_sponge((KECCAK_CTX*)ctx, 1024, 576);
		break;
	case 224:
		init_sponge((KECCAK_CTX*)ctx, 1152, 448);
		break;
	case 256:
		init_sponge((KECCAK_CTX*)ctx, 1088, 512);
		break;
	case 384:
		init_sponge((KECCAK_CTX*)ctx, 832, 768);
		break;
	case 512:
		init_sponge((KECCAK_CTX*)ctx, 576, 1024);
		break;
	default:
		return BAD_HASHLEN;
	}
	ctx->fixedOutputLength = hashbitlen;
	return SUCCESS;
}

HashReturn
KECCAK_Update(KECCAK_CTX *ctx, const uint8_t *data, uint64_t databitlen)
{
	HashReturn ret;

	if ((databitlen % 8) == 0) {
		return absorb((KECCAK_CTX*)ctx, data, databitlen);
	}
	ret = absorb((KECCAK_CTX*)ctx, data, databitlen - (databitlen % 8));
	if (ret == SUCCESS) {
		uint8_t lastByte; 

		/* Align the last partial byte to the least significant bits */
		lastByte = data[(unsigned long)databitlen/8] >> (8 - (databitlen % 8));
		return absorb((KECCAK_CTX*)ctx, &lastByte, databitlen % 8);
	}
	return ret;
}

HashReturn
KECCAK_Final(KECCAK_CTX *ctx, uint8_t *hashval)
{
	return squeeze(ctx, hashval, ctx->fixedOutputLength);
}
