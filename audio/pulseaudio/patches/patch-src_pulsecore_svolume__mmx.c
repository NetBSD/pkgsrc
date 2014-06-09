$NetBSD: patch-src_pulsecore_svolume__mmx.c,v 1.2 2014/06/09 13:08:19 ryoon Exp $

Avoid bad register usage on OSX 32-bit.

--- src/pulsecore/svolume_mmx.c.orig	2014-02-22 11:03:55.000000000 +0000
+++ src/pulsecore/svolume_mmx.c
@@ -34,7 +34,7 @@
 
 #include "sample-util.h"
 
-#if (!defined(__FreeBSD__) && defined (__i386__)) || defined (__amd64__)
+#if ((!defined(__FreeBSD__) || defined(__APPLE__)) && defined (__i386__)) || defined (__amd64__)
 /* in s: 2 int16_t samples
  * in v: 2 int32_t volumes, fixed point 16:16
  * out s: contains scaled and clamped int16_t samples.
@@ -243,7 +243,7 @@ static void pa_volume_s16re_mmx(int16_t 
 #endif /* (!defined(__FreeBSD__) && defined (__i386__)) || defined (__amd64__) */
 
 void pa_volume_func_init_mmx(pa_cpu_x86_flag_t flags) {
-#if (!defined(__FreeBSD__) && defined (__i386__)) || defined (__amd64__)
+#if ((!defined(__FreeBSD__) || defined(__APPLE__)) && defined (__i386__)) || defined (__amd64__)
     if ((flags & PA_CPU_X86_MMX) && (flags & PA_CPU_X86_CMOV)) {
         pa_log_info("Initialising MMX optimized volume functions.");
 
