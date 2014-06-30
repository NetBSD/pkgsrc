$NetBSD: patch-src_pulsecore_svolume__sse.c,v 1.3 2014/06/30 11:08:54 jperkin Exp $

Avoid bad register usage on OSX 32-bit.

--- src/pulsecore/svolume_sse.c.orig	2014-02-22 11:05:30.000000000 +0000
+++ src/pulsecore/svolume_sse.c
@@ -34,7 +34,7 @@
 
 #include "sample-util.h"
 
-#if (!defined(__FreeBSD__) && defined (__i386__)) || defined (__amd64__)
+#if ((!defined(__FreeBSD__) && !defined(__APPLE__)) && defined (__i386__)) || defined (__amd64__)
 
 #define VOLUME_32x16(s,v)                  /* .. |   vh  |   vl  | */                   \
       " pxor %%xmm4, %%xmm4          \n\t" /* .. |    0  |    0  | */                   \
@@ -254,7 +254,7 @@ static void pa_volume_s16re_sse2(int16_t
 #endif /* (!defined(__FreeBSD__) && defined (__i386__)) || defined (__amd64__) */
 
 void pa_volume_func_init_sse(pa_cpu_x86_flag_t flags) {
-#if (!defined(__FreeBSD__) && defined (__i386__)) || defined (__amd64__)
+#if ((!defined(__FreeBSD__) && !defined(__APPLE__)) && defined (__i386__)) || defined (__amd64__)
     if (flags & PA_CPU_X86_SSE2) {
         pa_log_info("Initialising SSE2 optimized volume functions.");
 
