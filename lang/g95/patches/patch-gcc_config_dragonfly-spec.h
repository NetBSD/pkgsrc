$NetBSD: patch-gcc_config_dragonfly-spec.h,v 1.1 2013/05/20 05:47:34 adam Exp $

DragonFly BSD support.

--- ../gcc-4.1.2/gcc/config/dragonfly-spec.h.orig	2013-05-19 08:50:27.000000000 +0000
+++ ../gcc-4.1.2/gcc/config/dragonfly-spec.h
@@ -0,0 +1,117 @@
+/* Base configuration file for all DragonFly targets.
+   Copyright (C) 1999, 2000, 2001, 2004, 2005 Free Software Foundation, Inc.
+
+This file is part of GCC.
+
+GCC is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2, or (at your option)
+any later version.
+
+GCC is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with GCC; see the file COPYING.  If not, write to
+the Free Software Foundation, 59 Temple Place - Suite 330,
+Boston, MA 02111-1307, USA.  */
+
+/* Common DragonFly configuration. 
+   All DragonFly architectures should include this file, which will specify
+   their commonalities.
+   Adapted from gcc/config/freebsd.h by 
+   David O'Brien <obrien@FreeBSD.org>
+   Loren J. Rittle <ljrittle@acm.org>.  */
+
+
+/* In case we need to know.  */
+#define USING_CONFIG_DRAGONFLY_SPEC 1
+
+/* This defines which switch letters take arguments.  On DragonFly, most of
+   the normal cases (defined in gcc.c) apply, and we also have -h* and
+   -z* options (for the linker) (coming from SVR4).
+   We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */
+
+#define DFLY_SWITCH_TAKES_ARG(CHAR)					\
+  (DEFAULT_SWITCH_TAKES_ARG (CHAR)					\
+    || (CHAR) == 'h'							\
+    || (CHAR) == 'z' /* ignored by ld */				\
+    || (CHAR) == 'R')
+
+/* This defines which multi-letter switches take arguments.  */
+
+#define DFLY_WORD_SWITCH_TAKES_ARG(STR)					\
+  (DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\
+   || !strcmp ((STR), "rpath") || !strcmp ((STR), "rpath-link")		\
+   || !strcmp ((STR), "soname") || !strcmp ((STR), "defsym") 		\
+   || !strcmp ((STR), "assert") || !strcmp ((STR), "dynamic-linker"))
+
+#define DFLY_TARGET_OS_CPP_BUILTINS()					\
+  do									\
+    {									\
+	builtin_define ("__DragonFly__");				\
+	builtin_define_std ("unix");					\
+	builtin_define ("__KPRINTF_ATTRIBUTE__");		       	\
+	builtin_assert ("system=unix");					\
+	builtin_assert ("system=bsd");					\
+	builtin_assert ("system=DragonFly");				\
+	DFLY_TARGET_CPU_CPP_BUILTINS();					\
+    }									\
+  while (0)
+
+/* Define the default DragonFly-specific per-CPU hook code.  */
+#define DFLY_TARGET_CPU_CPP_BUILTINS() do {} while (0)
+
+/* Provide a CPP_SPEC appropriate for DragonFly.  We just deal with the GCC 
+   option `-posix', and PIC issues.  */
+
+#define DFLY_CPP_SPEC "							\
+  %(cpp_cpu)								\
+  %(cpp_arch)								\
+  %{fPIC|fpic|fPIE|fpie:-D__PIC__ -D__pic__}				\
+  %{posix:-D_POSIX_SOURCE}"
+
+/* Provide a STARTFILE_SPEC appropriate for DragonFly.  Here we add
+   the magical crtbegin.o file (see crtstuff.c) which provides part 
+	of the support for getting C++ file-scope static object constructed 
+	before entering `main'.  */
+   
+#define DFLY_STARTFILE_SPEC \
+  "%{!shared: \
+     %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \
+		       %{!p:%{profile:gcrt1.o%s} \
+			 %{!profile:crt1.o%s}}}} \
+   crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
+
+/* Provide a ENDFILE_SPEC appropriate for DragonFly.  Here we tack on
+   the magical crtend.o file (see crtstuff.c) which provides part of 
+	the support for getting C++ file-scope static object constructed 
+	before entering `main', followed by a normal "finalizer" file, 
+	`crtn.o'.  */
+
+#define DFLY_ENDFILE_SPEC \
+  "%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
+
+/* Provide a LIB_SPEC appropriate for DragonFly.  Just select the appropriate
+   libc, depending on whether we're doing profiling or need threads support.
+   (similar to the default, except no -lg, and no -p).  */
+
+#ifdef DFLY_NO_THREADS
+#define DFLY_LIB_SPEC "							\
+  %{pthread: %eThe -pthread option is only supported on DragonFly when gcc \
+is built with the --enable-threads configure-time option.}		\
+  %{!shared:								\
+    %{!pg: -lc}								\
+    %{pg:  -lc_p}							\
+  }"
+#else
+#define DFLY_LIB_SPEC "							\
+  %{!shared:								\
+    %{!pg: %{pthread:-lpthread} -lc}					\
+    %{pg:  %{pthread:-lpthread_p} -lc_p}				\
+  }"
+#endif
+
+#define DFLY_DYNAMIC_LINKER "/usr/libexec/ld-elf.so.2"
