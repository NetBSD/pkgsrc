/*	$NetBSD: cdefs.h,v 1.4 2024/03/19 00:59:01 nia Exp $	*/

/*-
 * Copyright (c) 2004 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Johnny C. Lam.
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

#ifndef _NBCOMPAT_SYS_CDEFS_H_
#define _NBCOMPAT_SYS_CDEFS_H_

#if HAVE_SYS_CDEFS_H
# include <sys/cdefs.h>
#endif

/*
 * Declare macros and functions that may be missing in <sys/cdefs.h>.
 */

#ifndef __IDSTRING
# define __IDSTRING(name,string) \
	static const char name[] __attribute__((__unused__)) = string
#endif

#ifndef __COPYRIGHT
# define __COPYRIGHT(_s)	__IDSTRING(copyright,_s)
#endif

#ifndef __RCSID
# define __RCSID(_s)		__IDSTRING(rcsid,_s)
#endif

#ifndef __P
# if defined(__STDC__) || defined(__cplusplus)
#  define __P(protos)	protos		/* full-blown ANSI C */
# else
#  define __P(protos)	()		/* traditional C preprocessor */
# endif
#endif

#ifndef __CONCAT
# if defined(__STDC__) || defined(__cplusplus)
#  define __CONCAT(x,y)	x ## y
# else
#  define __CONCAT(x,y)	x/**/y
# endif
#endif

#ifndef __BEGIN_DECLS
# if defined(__cplusplus)
#  define __BEGIN_DECLS	extern "C" {
# else
#  define __BEGIN_DECLS
# endif
#endif

#ifndef __END_DECLS
# if defined(__cplusplus)
#  define __END_DECLS	};
# else
#  define __END_DECLS
# endif
#endif

#ifndef __restrict
/*
 * C99 defines the restrict type qualifier keyword, which was made available
 * in GCC 2.92.
 */
# if __STDC_VERSION__ >= 199901L
#  define __restrict	restrict
# else
#  define __restrict	/* delete __restrict when not supported */
# endif
#endif

/*
 * The following macro is used to remove const cast-away warnings
 * from gcc -Wcast-qual; it should be used with caution because it
 * can hide valid errors; in particular most valid uses are in
 * situations where the API requires it, not to cast away string
 * constants. We don't use *intptr_t on purpose here and we are
 * explicit about unsigned long so that we don't have additional
 * dependencies.
 */
#ifndef __UNCONST
#  define __UNCONST(a)	((void *)(unsigned long)(const void *)(a))
#endif

#endif	/* !_NBCOMPAT_SYS_CDEFS_H_ */
