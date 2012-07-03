$NetBSD: manual-patch-avidemux_ADM__libraries_ffmpeg_libavcodec_x86_dsputil__mmx.c,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_libraries/ffmpeg/libavcodec/x86/dsputil_mmx.c.orig	2012-07-03 11:38:24.000000000 +0000
+++ avidemux/ADM_libraries/ffmpeg/libavcodec/x86/dsputil_mmx.c
@@ -611,7 +611,7 @@ static void add_hfyu_median_prediction_c
     __asm__ volatile(
         "mov    %7, %3 \n"
         "1: \n"
-        "movzx (%3,%4), %2 \n"
+        "movzbl (%3,%4), %2 \n"
         "mov    %2, %k3 \n"
         "sub   %b1, %b3 \n"
         "add   %b0, %b3 \n"
