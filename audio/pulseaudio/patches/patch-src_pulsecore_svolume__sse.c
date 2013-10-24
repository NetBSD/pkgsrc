$NetBSD: patch-src_pulsecore_svolume__sse.c,v 1.1 2013/10/24 17:48:53 jperkin Exp $

Avoid bad register usage on OSX 32-bit.

--- src/pulsecore/svolume_sse.c.orig	2012-07-19 11:29:39.000000000 +0000
+++ src/pulsecore/svolume_sse.c
@@ -34,7 +34,7 @@
 
 #include "sample-util.h"
 
-#if defined (__i386__) || defined (__amd64__)
+#if (defined (__i386__) && !defined(__APPLE__)) || defined (__amd64__)
 
 #define VOLUME_32x16(s,v)                  /* .. |   vh  |   vl  | */                   \
       " pxor %%xmm4, %%xmm4          \n\t" /* .. |    0  |    0  | */                   \
@@ -335,7 +335,7 @@ static void run_test(void) {
 #endif /* defined (__i386__) || defined (__amd64__) */
 
 void pa_volume_func_init_sse(pa_cpu_x86_flag_t flags) {
-#if defined (__i386__) || defined (__amd64__)
+#if (defined (__i386__) && !defined(__APPLE__)) || defined (__amd64__)
 
 #ifdef RUN_TEST
     run_test();
