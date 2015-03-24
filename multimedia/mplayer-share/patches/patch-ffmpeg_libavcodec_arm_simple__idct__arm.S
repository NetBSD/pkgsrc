$NetBSD: patch-ffmpeg_libavcodec_arm_simple__idct__arm.S,v 1.1 2015/03/24 14:27:20 joerg Exp $

--- ffmpeg/libavcodec/arm/simple_idct_arm.S.orig	2015-03-23 19:55:14.000000000 +0000
+++ ffmpeg/libavcodec/arm/simple_idct_arm.S
@@ -489,7 +489,7 @@ __end_bef_a_evaluation:
         sub r4, r6, r11          @ R4=a0-W2*ROWr16[2] (a3)
         add r6, r6, r11          @ R6=a0+W2*ROWr16[2] (a0)
         bal __end_a_evaluation
-
+endfunc
 
         .align
 __constant_ptr__:  @@ see #defines at the beginning of the source code for values.
