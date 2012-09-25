$NetBSD: patch-src_common.h,v 1.1 2012/09/25 11:45:11 ryoon Exp $

Add SONY Bravia support
http://blog-imgs-30.fc2.com/h/o/r/horip/mediatomb-0_12_1_bravia_support_0_1_patch.txt

--- src/common.h.orig	2010-03-25 14:58:11.000000000 +0000
+++ src/common.h
@@ -83,6 +83,7 @@
     #define D_JPEG_TN                   "JPEG_TN"
     #define D_JPEG_SM_ICO               "JPEG_SM_ICO"
     #define D_JPEG_LRG_ICO              "JPEG_LRG_ICO"
+    #define D_MPEG_PS_NTSC		"MPEG_PS_NTSC"
 #endif
 // fixed CdsObjectIDs
 #define CDS_ID_BLACKHOLE                -1
