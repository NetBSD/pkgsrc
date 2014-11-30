$NetBSD: patch-mono_profiler_proflog.c,v 1.2 2014/11/30 08:40:51 spz Exp $

SunOS libelf does not support largefile.

--- mono/profiler/proflog.c.orig	2014-09-22 13:23:09.000000000 +0000
+++ mono/profiler/proflog.c
@@ -38,6 +38,10 @@
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
