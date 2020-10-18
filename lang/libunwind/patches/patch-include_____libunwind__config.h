$NetBSD: patch-include_____libunwind__config.h,v 1.1 2020/10/18 17:06:35 he Exp $

Gcc doesn't define __ppc__, but defines __powerpc__ on NetBSD/powerpc.

--- include/__libunwind_config.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ include/__libunwind_config.h
@@ -50,7 +50,7 @@
 #  define _LIBUNWIND_CONTEXT_SIZE 167
 #  define _LIBUNWIND_CURSOR_SIZE 179
 #  define _LIBUNWIND_HIGHEST_DWARF_REGISTER _LIBUNWIND_HIGHEST_DWARF_REGISTER_PPC64
-# elif defined(__ppc__)
+# elif defined(__ppc__) || defined(__powerpc__)
 #  define _LIBUNWIND_TARGET_PPC 1
 #  define _LIBUNWIND_CONTEXT_SIZE 117
 #  define _LIBUNWIND_CURSOR_SIZE 124
