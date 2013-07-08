$NetBSD: patch-src_benchmark.h,v 1.1 2013/07/08 08:30:01 wiz Exp $

--- src/benchmark.h.orig	2013-05-25 11:06:37.000000000 +0000
+++ src/benchmark.h
@@ -24,7 +24,7 @@
 # include <windows.h>
 #endif
 
-#if defined(HAVE_CLOCK_GETTIME)
+#if defined(HAVE_CLOCK_GETTIME) && defined(CLOCK_PROCESS_CPUTIME_ID)
 # undef gettime
 # define gettime(x) clock_gettime(CLOCK_PROCESS_CPUTIME_ID, x)
 #else
