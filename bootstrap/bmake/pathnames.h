/*	$NetBSD: pathnames.h,v 1.1.1.1 2004/03/11 13:04:12 grant Exp $	*/

/*
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)pathnames.h	5.2 (Berkeley) 6/1/90
 *	$Id: pathnames.h,v 1.1.1.1 2004/03/11 13:04:12 grant Exp $
 */

#if !defined(NO_PATH_OBJDIRPREFIX) && !defined(_PATH_OBJDIRPREFIX)
# define _PATH_OBJDIRPREFIX	"/usr/obj"
#endif
#define	_PATH_OBJDIR		"obj"
#define	_PATH_DEFSHELLDIR	"/bin"
#define	_PATH_DEFSYSMK		"sys.mk"
#define _path_defsyspath	"/usr/share/mk:/usr/local/share/mk:/opt/share/mk"
#ifndef _PATH_DEFSYSPATH
# ifdef _PATH_PREFIX_SYSPATH
#   define  _PATH_DEFSYSPATH	_PATH_PREFIX_SYSPATH ":" _path_defsyspath
# else
#   define  _PATH_DEFSYSPATH	_path_defsyspath
# endif
#endif
