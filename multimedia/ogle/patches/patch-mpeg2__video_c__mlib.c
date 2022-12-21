$NetBSD: patch-mpeg2__video_c__mlib.c,v 1.1 2022/12/21 14:14:17 wiz Exp $

Remove inline to fix build with gcc 10.

--- mpeg2_video/c_mlib.c.orig	2003-02-15 21:42:30.000000000 +0000
+++ mpeg2_video/c_mlib.c
@@ -75,7 +75,7 @@ mlib_Init(void)
 {
 }
 
-inline void
+void
 mlib_VideoCopyRef_U8_U8 (uint8_t *curr_block,
                          const uint8_t *ref_block,
                          const int32_t width,
