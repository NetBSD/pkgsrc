$NetBSD: patch-src_pulsecore_svolume__mmx.c,v 1.1 2013/10/24 17:48:53 jperkin Exp $

Avoid bad register usage on OSX 32-bit.

--- src/pulsecore/svolume_mmx.c.orig	2012-07-19 11:29:39.000000000 +0000
+++ src/pulsecore/svolume_mmx.c
@@ -34,7 +34,7 @@
 
 #include "sample-util.h"
 
-#if defined (__i386__) || defined (__amd64__)
+#if (defined (__i386__) && !defined(__APPLE__)) || defined (__amd64__)
 /* in s: 2 int16_t samples
  * in v: 2 int32_t volumes, fixed point 16:16
  * out s: contains scaled and clamped int16_t samples.
@@ -328,7 +328,7 @@ static void run_test(void) {
 
 
 void pa_volume_func_init_mmx(pa_cpu_x86_flag_t flags) {
-#if defined (__i386__) || defined (__amd64__)
+#if (defined (__i386__) && !defined(__APPLE__)) || defined (__amd64__)
 
 #ifdef RUN_TEST
     run_test();
