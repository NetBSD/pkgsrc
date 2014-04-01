$NetBSD: patch-libavcodec_libx265.c,v 1.1 2014/04/01 10:51:49 adam Exp $

Fix building with newer x265.

--- libavcodec/libx265.c.orig	2014-03-25 13:51:11.000000000 +0000
+++ libavcodec/libx265.c
@@ -120,11 +121,11 @@ static av_cold int libx265_encode_init(A
     av_reduce(&sar_num, &sar_den,
               avctx->sample_aspect_ratio.num,
               avctx->sample_aspect_ratio.den, 4096);
-    ctx->params->bEnableVuiParametersPresentFlag = 1;
-    ctx->params->bEnableAspectRatioIdc           = 1;
-    ctx->params->aspectRatioIdc                  = 255;
-    ctx->params->sarWidth                        = sar_num;
-    ctx->params->sarHeight                       = sar_den;
+    ctx->params->vui.bEnableVuiParametersPresentFlag = 1;
+    ctx->params->vui.bEnableAspectRatioIdc           = 1;
+    ctx->params->vui.aspectRatioIdc                  = 255;
+    ctx->params->vui.sarWidth                        = sar_num;
+    ctx->params->vui.sarHeight                       = sar_den;
 
     if (x265_max_bit_depth == 8)
         ctx->params->internalBitDepth = 8;
