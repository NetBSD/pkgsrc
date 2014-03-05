/*	$NetBSD: rmd160.h,v 1.1.1.1 2014/03/05 05:09:44 agc Exp $	*/

/********************************************************************\
 *
 *      FILE:     rmd160.h
 *
 *      CONTENTS: Header file for a sample C-implementation of the
 *                RIPEMD-160 hash-function. 
 *      TARGET:   any computer with an ANSI C compiler
 *
 *      AUTHOR:   Antoon Bosselaers, ESAT-COSIC
 *      DATE:     1 March 1996
 *      VERSION:  1.0
 *
 *      Copyright (c) Katholieke Universiteit Leuven
 *      1996, All Rights Reserved
 *
\********************************************************************/

/*
 * from OpenBSD: rmd160.h,v 1.4 1999/08/16 09:59:04 millert Exp
 */

#ifndef _RMD160_H_
#define _RMD160_H_

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

typedef struct {
	uint32_t	state[5];	/* state (ABCDE) */
	uint32_t	length[2];	/* number of bits */
	uint8_t		bbuffer[64];    /* overflow buffer */
	uint32_t	buflen;		/* number of chars in bbuffer */
} RMD160_CTX;

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

void	RMD160Init(RMD160_CTX *);
void	RMD160Transform(uint32_t[5], const uint32_t[16]);
void	RMD160Update(RMD160_CTX *, const uint8_t *, size_t);
void	RMD160Final(uint8_t[20], RMD160_CTX *);
#ifndef	_KERNEL
char	*RMD160End(RMD160_CTX *, char *);
char	*RMD160File(char *, char *);
char	*RMD160Data(const uint8_t *, size_t, char *);
#endif /* _KERNEL */

__END_DECLS

#endif  /* !_RMD160_H_ */
