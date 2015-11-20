$NetBSD: patch-libavcodec_libvpxenc.c,v 1.1 2015/11/20 18:33:38 tron Exp $

Fix build with libvpx version 1.5.0 and newer. Fix taken from here:

http://git.videolan.org/?p=ffmpeg.git;a=commitdiff;h=6540fe04a3f9a11ba7084a49b3ee5fa2fc5b32ab#patch1

--- libavcodec/libvpxenc.c.orig	2015-09-09 02:17:45.000000000 +0100
+++ libavcodec/libvpxenc.c	2015-11-20 18:25:02.000000000 +0000
@@ -104,19 +104,11 @@
 
 /** String mappings for enum vp8e_enc_control_id */
 static const char *const ctlidstr[] = {
-    [VP8E_UPD_ENTROPY]           = "VP8E_UPD_ENTROPY",
-    [VP8E_UPD_REFERENCE]         = "VP8E_UPD_REFERENCE",
-    [VP8E_USE_REFERENCE]         = "VP8E_USE_REFERENCE",
-    [VP8E_SET_ROI_MAP]           = "VP8E_SET_ROI_MAP",
-    [VP8E_SET_ACTIVEMAP]         = "VP8E_SET_ACTIVEMAP",
-    [VP8E_SET_SCALEMODE]         = "VP8E_SET_SCALEMODE",
     [VP8E_SET_CPUUSED]           = "VP8E_SET_CPUUSED",
     [VP8E_SET_ENABLEAUTOALTREF]  = "VP8E_SET_ENABLEAUTOALTREF",
     [VP8E_SET_NOISE_SENSITIVITY] = "VP8E_SET_NOISE_SENSITIVITY",
-    [VP8E_SET_SHARPNESS]         = "VP8E_SET_SHARPNESS",
     [VP8E_SET_STATIC_THRESHOLD]  = "VP8E_SET_STATIC_THRESHOLD",
     [VP8E_SET_TOKEN_PARTITIONS]  = "VP8E_SET_TOKEN_PARTITIONS",
-    [VP8E_GET_LAST_QUANTIZER]    = "VP8E_GET_LAST_QUANTIZER",
     [VP8E_SET_ARNR_MAXFRAMES]    = "VP8E_SET_ARNR_MAXFRAMES",
     [VP8E_SET_ARNR_STRENGTH]     = "VP8E_SET_ARNR_STRENGTH",
     [VP8E_SET_ARNR_TYPE]         = "VP8E_SET_ARNR_TYPE",
