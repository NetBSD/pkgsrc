$NetBSD: patch-libavcodec_libvpxenc.c,v 1.1 2015/11/20 18:36:12 ryoon Exp $

https://github.com/FFmpeg/FFmpeg/commit/6540fe04a3f9a11ba7084a49b3ee5fa2fc5b32ab#diff-2717f08354d3468cf8024461959fcc8a

--- libavcodec/libvpxenc.c.orig	2015-03-12 19:53:52.000000000 +0000
+++ libavcodec/libvpxenc.c
@@ -78,19 +78,11 @@ typedef struct VP8EncoderContext {
 
 /** String mappings for enum vp8e_enc_control_id */
 static const char *ctlidstr[] = {
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
