$NetBSD: patch-libgo_runtime_proc.c,v 1.1 2013/04/02 09:57:52 jperkin Exp $

SunOS libelf does not support largefile.

--- libgo/runtime/proc.c.orig	2012-07-26 01:57:22.000000000 +0000
+++ libgo/runtime/proc.c
@@ -10,6 +10,10 @@
 #include "config.h"
 
 #ifdef HAVE_DL_ITERATE_PHDR
+#ifdef __sun
+#undef _FILE_OFFSET_BITS
+#define _FILE_OFFSET_BITS 32
+#endif
 #include <link.h>
 #endif
 
