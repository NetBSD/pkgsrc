$NetBSD: patch-src_pulsecore_svolume__mmx.c,v 1.4 2015/02/21 23:13:10 ryoon Exp $

Avoid bad register usage on OSX 32-bit.

--- src/pulsecore/svolume_mmx.c.orig	2015-02-12 14:10:35.000000000 +0000
+++ src/pulsecore/svolume_mmx.c
@@ -32,7 +32,7 @@
 
 #include "sample-util.h"
 
-#if (!defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && defined (__i386__)) || defined (__amd64__)
+#if (!defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__APPLE__) && defined (__i386__)) || defined (__amd64__)
 /* in s: 2 int16_t samples
  * in v: 2 int32_t volumes, fixed point 16:16
  * out s: contains scaled and clamped int16_t samples.
@@ -241,7 +241,7 @@ static void pa_volume_s16re_mmx(int16_t 
 #endif /* (!defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && defined (__i386__)) || defined (__amd64__) */
 
 void pa_volume_func_init_mmx(pa_cpu_x86_flag_t flags) {
-#if (!defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && defined (__i386__)) || defined (__amd64__)
+#if (!defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__APPLE__) && defined (__i386__)) || defined (__amd64__)
     if ((flags & PA_CPU_X86_MMX) && (flags & PA_CPU_X86_CMOV)) {
         pa_log_info("Initialising MMX optimized volume functions.");
 
