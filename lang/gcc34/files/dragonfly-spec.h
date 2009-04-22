/* Base configuration file for all FreeBSD targets.
   Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* Common DragonFly configuration. 
   All DragonFly architectures should include this file, which will specify
   their commonalities.
   Adapted from gcc/config/freebsd.h by 
   David O'Brien <obrien@FreeBSD.org>
   Loren J. Rittle <ljrittle@acm.org>.  */


/* In case we need to know.  */
#define USING_CONFIG_DRAGONFLY_SPEC 1

/* This defines which switch letters take arguments.  On DragonFly, most of
   the normal cases (defined in gcc.c) apply, and we also have -h* and
   -z* options (for the linker) (coming from SVR4).
   We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */

#define DFBSD_SWITCH_TAKES_ARG(CHAR)					\
  (DEFAULT_SWITCH_TAKES_ARG (CHAR)					\
    || (CHAR) == 'h'							\
    || (CHAR) == 'z' /* ignored by ld */				\
    || (CHAR) == 'R')

/* This defines which multi-letter switches take arguments.  */

#define DFBSD_WORD_SWITCH_TAKES_ARG(STR)					\
  (DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\
   || !strcmp ((STR), "rpath") || !strcmp ((STR), "rpath-link")		\
   || !strcmp ((STR), "soname") || !strcmp ((STR), "defsym") 		\
   || !strcmp ((STR), "assert") || !strcmp ((STR), "dynamic-linker"))

#define DFBSD_TARGET_OS_CPP_BUILTINS()					\
  do									\
    {									\
	if (DFBSD_MAJOR == 4)						\
	  builtin_define ("__DragonFly__=4");			       	\
	else if (DFBSD_MAJOR == 3)					\
	  builtin_define ("__DragonFly__=3");			       	\
	if (DFBSD_MAJOR == 2)						\
	  builtin_define ("__DragonFly__=2");			       	\
	else if (DFBSD_MAJOR == 1)					\
	  builtin_define ("__DragonFly__=1");			       	\
	else								\
	  builtin_define ("__DragonFly__");			       	\
	builtin_define_std ("unix");					\
	builtin_define ("__KPRINTF_ATTRIBUTE__");		       	\
	builtin_assert ("system=unix");					\
	builtin_assert ("system=bsd");					\
	builtin_assert ("system=DragonFly");				\
	DFBSD_TARGET_CPU_CPP_BUILTINS();					\
    }									\
  while (0)

/* Define the default DragonFly-specific per-CPU hook code. */
#define DFBSD_TARGET_CPU_CPP_BUILTINS() do {} while (0)

/* Provide a CPP_SPEC appropriate for DragonFly.  We just deal with the GCC 
   option `-posix', and PIC issues.  */

#define DFBSD_CPP_SPEC "							\
  %(cpp_cpu)								\
  %{fPIC|fpic|fPIE|fpie:-D__PIC__ -D__pic__}				\
  %{posix:-D_POSIX_SOURCE}"

/* Provide a STARTFILE_SPEC appropriate for DragonFly.  Here we add
   the magical crtbegin.o file (see crtstuff.c) which provides part 
	of the support for getting C++ file-scope static object constructed 
	before entering `main'.  */
   
#define DFBSD_STARTFILE_SPEC \
  "%{!shared: \
     %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \
		       %{!p:%{profile:gcrt1.o%s} \
			 %{!profile:crt1.o%s}}}} \
   crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"

/* Provide a ENDFILE_SPEC appropriate for DragonFly.  Here we tack on
   the magical crtend.o file (see crtstuff.c) which provides part of 
	the support for getting C++ file-scope static object constructed 
	before entering `main', followed by a normal "finalizer" file, 
	`crtn.o'.  */

#define DFBSD_ENDFILE_SPEC \
  "%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"

/* Provide a LIB_SPEC appropriate for DragonFly as configured and as
   required by the user-land thread model. */

/* Provide a LIB_SPEC appropriate for DragonFly.  Just select the appropriate
   libc, depending on whether we're doing profiling or need threads support.
   (similar to the default, except no -lg, and no -p).  */

#ifdef DFBSD_NO_THREADS
#define DFBSD_LIB_SPEC "							\
  %{pthread: %eThe -pthread option is only supported on DragonFly when gcc	\
is built with the --enable-threads configure-time option.}			\
  %{!shared:                                                            \
    %{!pg: -lc}                                                         \
    %{pg:  -lc_p}                                                       \
  }"
#else
#define DFBSD_LIB_SPEC "							\
  %{!shared:                                                            \
    %{!pg: %{pthread:-lpthread} -lc}                                    \
    %{pg:  %{pthread:-lpthread_p} -lc_p}                                \
  }"
#endif

#define DFBSD_DYNAMIC_LINKER "/usr/libexec/ld-elf.so.2"
