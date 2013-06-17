$NetBSD: patch-mono_profiler_proflog.c,v 1.1 2013/06/17 13:14:41 jperkin Exp $

SunOS libelf does not support 64-bit.

--- mono/profiler/proflog.c.orig	2012-01-30 18:01:23.000000000 +0000
+++ mono/profiler/proflog.c
@@ -33,6 +33,10 @@
 #ifdef HAVE_EXECINFO_H
 #include <execinfo.h>
 #endif
+#ifdef __sun
+#undef _FILE_OFFSET_BITS
+#define _FILE_OFFSET_BITS 32
+#endif
 #ifdef HAVE_LINK_H
 #include <link.h>
 #endif
