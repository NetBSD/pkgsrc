$NetBSD: patch-lib-src_libnyquist_nyquist_cmupv_src_cmupv.c,v 1.1 2020/05/23 15:51:28 nia Exp $

Build on systems without log2l (NetBSD 9...)

--- lib-src/libnyquist/nyquist/cmupv/src/cmupv.c.orig	2020-05-19 09:43:53.000000000 +0000
+++ lib-src/libnyquist/nyquist/cmupv/src/cmupv.c
@@ -218,7 +218,7 @@ typedef struct {
 //
 int round_log_power(int fftsize, int *size_ptr)
 {
-    long double log2_fft = log2l(fftsize);
+    long double log2_fft = log2(fftsize);
     int round_log2_fft = (int) log2_fft;
     if (round_log2_fft < log2_fft) {
         round_log2_fft += 1;
