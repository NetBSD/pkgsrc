$NetBSD: patch-mono_profiler_proflog.c,v 1.1 2013/06/05 17:03:55 jperkin Exp $

SunOS libelf does not support largefile.

--- mono/profiler/proflog.c.orig	2013-04-25 09:01:57.000000000 +0000
+++ mono/profiler/proflog.c
@@ -36,6 +36,10 @@
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
