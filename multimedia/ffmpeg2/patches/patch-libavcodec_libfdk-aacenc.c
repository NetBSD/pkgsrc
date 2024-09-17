$NetBSD: patch-libavcodec_libfdk-aacenc.c,v 1.1 2024/09/17 08:31:29 adam Exp $

Fix for never fdk-aac.

--- libavcodec/libfdk-aacenc.c.orig	2024-09-17 08:17:41.956196571 +0000
+++ libavcodec/libfdk-aacenc.c
@@ -26,6 +26,14 @@
 #include "audio_frame_queue.h"
 #include "internal.h"
 
+#ifdef AACENCODER_LIB_VL0
+#define FDKENC_VER_AT_LEAST(vl0, vl1) \
+    ((AACENCODER_LIB_VL0 > vl0) || \
+     (AACENCODER_LIB_VL0 == vl0 && AACENCODER_LIB_VL1 >= vl1))
+#else
+#define FDKENC_VER_AT_LEAST(vl0, vl1) 0
+#endif 
+
 typedef struct AACContext {
     const AVClass *class;
     HANDLE_AACENCODER handle;
@@ -286,7 +294,11 @@ static av_cold int aac_encode_init(AVCod
     }
 
     avctx->frame_size = info.frameLength;
+#if FDKENC_VER_AT_LEAST(4, 0) // 4.0.0   
+    avctx->initial_padding = info.nDelay; 
+#else 
     avctx->initial_padding = info.encoderDelay;
+#endif
     ff_af_queue_init(avctx, &s->afq);
 
     if (avctx->flags & AV_CODEC_FLAG_GLOBAL_HEADER) {
