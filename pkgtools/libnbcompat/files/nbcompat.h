/*	$NetBSD: nbcompat.h,v 1.36 2004/08/10 18:47:55 jlam Exp $	*/

/*-
 * Copyright (c) 2003 The NetBSD Foundation, Inc.
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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
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

#ifndef _NBCOMPAT_H
#define _NBCOMPAT_H

#include <nbcompat/nbconfig.h>
#include <nbcompat/nbtypes.h>

#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/wait.h>

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <termios.h>

#include <nbcompat/fnmatch.h>
#include <nbcompat/grp.h>
#include <nbcompat/limits.h>
#include <nbcompat/paths.h>
#include <nbcompat/pwd.h>
#include <nbcompat/queue.h>
#include <nbcompat/stat.h>
#include <nbcompat/statvfs.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/stdio.h>
#include <nbcompat/string.h>
#include <nbcompat/time.h>
#include <nbcompat/tzfile.h>
#include <nbcompat/unistd.h>
#include <nbcompat/util.h>

#if !HAVE_POLL
# undef HAVE_POLL_H
# undef HAVE_SYS_POLL_H
# include <nbcompat/poll.h>
#endif

#if HAVE_DIRENT_H
# include <dirent.h>
#else
# define dirent direct
# if HAVE_SYS_NDIR_H
#  include <sys/ndir.h>
# endif
# if HAVE_SYS_DIR_H
#  include <sys/dir.h>
# endif
# if HAVE_NDIR_H
#  include <ndir.h>
# endif
#endif

#if HAVE_NBCOMPAT_FTS
# if HAVE_FTS_H
#  undef HAVE_FTS_H
# endif
# include <nbcompat/fts.h>
#endif

#if HAVE_ASSERT_H
# include <assert.h>
#endif

#if HAVE_ERR_H
# include <err.h>
#else
# include <nbcompat/err.h>
#endif

#if HAVE_NBCOMPAT_GLOB
# if HAVE_GLOB_H
#  undef HAVE_GLOB_H
# endif
# include <nbcompat/glob.h>
#endif

#if HAVE_SYS_MKDEV_H
# include <sys/mkdev.h>
# if !defined(makedev) && defined(mkdev)
#  define makedev mkdev
# endif
#endif

#if HAVE_TERMCAP_H
# include <termcap.h>
#else
int	 tgetent(char *, const char *);
char	*tgetstr(const char *, char **);
int	 tgetflag(const char *);
int	 tgetnum(const char *);
char	*tgoto(const char *, int, int);
void	 tputs(const char *, int, int (*)(int));
#endif

#if HAVE_NBCOMPAT_MD5INIT
# if HAVE_MD5_H
#  undef HAVE_MD5_H
# endif
#endif

#if HAVE_NBCOMPAT_MD5
# if HAVE_MD5_H
#  undef HAVE_MD5_H
# endif
# include <nbcompat/md5.h>
#endif

#if HAVE_NBCOMPAT_RMD160
# if HAVE_RMD160_H
#  undef HAVE_RMD160_H
# endif
# include <nbcompat/rmd160.h>
#endif

#if HAVE_NBCOMPAT_SHA1
# if HAVE_SHA1_H
#  undef HAVE_SHA1_H
# endif
# include <nbcompat/sha1.h>
#endif

#if HAVE_NBCOMPAT_VIS
# if HAVE_VIS_H
#  undef HAVE_VIS_H
# endif
# include <nbcompat/vis.h>
#endif

#if HAVE_NBCOMPAT_GETOPT_LONG
# if HAVE_GETOPT_H
#  undef HAVE_GETOPT_H
# endif
# include <nbcompat/getopt.h>
#endif

#if !HAVE_D_NAMLEN
# define DIRENT_MISSING_D_NAMLEN
#endif

#if !HAVE_ISBLANK
int     isblank(int);
#endif

#if HAVE_GETPASSPHRASE
# define getpass getpassphrase
#endif

#if !defined(MIN)
# define MIN(a, b)	((a) < (b) ? (a) : (b))
#endif
#if !defined(MAX)
# define MAX(a, b)	((a) < (b) ? (b) : (a))
#endif

#endif /* !_NBCOMPAT_H */
