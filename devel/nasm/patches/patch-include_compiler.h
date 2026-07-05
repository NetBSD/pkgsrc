$NetBSD: patch-include_compiler.h,v 1.4 2026/07/05 12:11:26 adam Exp $

Fix SunOS, presence of stdbit.h doesn't mean endian.h shouldn't be included.

--- include/compiler.h.orig	2026-06-29 03:44:05.000000000 +0000
+++ include/compiler.h
@@ -96,6 +96,9 @@
 #ifdef HAVE_STDBIT_H
 
 # include <stdbit.h>
+#ifdef __sun
+#include <endian.h>
+#endif
 
 # undef WORDS_LITTLEENDIAN
 # undef WORDS_BIGENDIAN
