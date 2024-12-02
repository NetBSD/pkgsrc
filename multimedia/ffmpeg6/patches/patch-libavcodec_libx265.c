$NetBSD: patch-libavcodec_libx265.c,v 1.1 2024/12/02 19:30:59 markd Exp $

Fix build with x265 >=210

https://git.ffmpeg.org/gitweb/ffmpeg.git/commit/1f801dfdb5
https://git.ffmpeg.org/gitweb/ffmpeg.git/commit/4571c80b40

--- libavcodec/libx265.c.orig	2024-08-01 23:22:48.000000000 +0000
+++ libavcodec/libx265.c
@@ -581,7 +581,13 @@ static int libx265_encode_frame(AVCodecC
 {
     libx265Context *ctx = avctx->priv_data;
     x265_picture x265pic;
-    x265_picture x265pic_out = { 0 };
+#if (X265_BUILD >= 210) && (X265_BUILD < 213)
+    x265_picture x265pic_layers_out[MAX_SCALABLE_LAYERS];
+    x265_picture* x265pic_lyrptr_out[MAX_SCALABLE_LAYERS];
+#else
+    x265_picture x265pic_solo_out = { 0 };
+#endif
+    x265_picture* x265pic_out;
     x265_nal *nal;
     x265_sei *sei;
     uint8_t *dst;
@@ -704,8 +710,16 @@ FF_ENABLE_DEPRECATION_WARNINGS
         }
     }
 
+#if (X265_BUILD >= 210) && (X265_BUILD < 213)
+    for (i = 0; i < MAX_SCALABLE_LAYERS; i++)
+        x265pic_lyrptr_out[i] = &x265pic_layers_out[i];
+
+    ret = ctx->api->encoder_encode(ctx->encoder, &nal, &nnal,
+                                   pic ? &x265pic : NULL, x265pic_lyrptr_out);
+#else
     ret = ctx->api->encoder_encode(ctx->encoder, &nal, &nnal,
-                                   pic ? &x265pic : NULL, &x265pic_out);
+                                   pic ? &x265pic : NULL, &x265pic_solo_out);
+#endif
 
     for (i = 0; i < sei->numPayloads; i++)
         av_free(sei->payloads[i].payload);
@@ -735,10 +749,16 @@ FF_ENABLE_DEPRECATION_WARNINGS
             pkt->flags |= AV_PKT_FLAG_KEY;
     }
 
-    pkt->pts = x265pic_out.pts;
-    pkt->dts = x265pic_out.dts;
+#if (X265_BUILD >= 210) && (X265_BUILD < 213)
+    x265pic_out = x265pic_lyrptr_out[0];
+#else
+    x265pic_out = &x265pic_solo_out;
+#endif
+
+    pkt->pts = x265pic_out->pts;
+    pkt->dts = x265pic_out->dts;
 
-    switch (x265pic_out.sliceType) {
+    switch (x265pic_out->sliceType) {
     case X265_TYPE_IDR:
     case X265_TYPE_I:
         pict_type = AV_PICTURE_TYPE_I;
@@ -756,16 +776,16 @@ FF_ENABLE_DEPRECATION_WARNINGS
     }
 
 #if X265_BUILD >= 130
-    if (x265pic_out.sliceType == X265_TYPE_B)
+    if (x265pic_out->sliceType == X265_TYPE_B)
 #else
-    if (x265pic_out.frameData.sliceType == 'b')
+    if (x265pic_out->frameData.sliceType == 'b')
 #endif
         pkt->flags |= AV_PKT_FLAG_DISPOSABLE;
 
-    ff_side_data_set_encoder_stats(pkt, x265pic_out.frameData.qp * FF_QP2LAMBDA, NULL, 0, pict_type);
+    ff_side_data_set_encoder_stats(pkt, x265pic_out->frameData.qp * FF_QP2LAMBDA, NULL, 0, pict_type);
 
-    if (x265pic_out.userData) {
-        int idx = (int)(intptr_t)x265pic_out.userData - 1;
+    if (x265pic_out->userData) {
+        int idx = (int)(intptr_t)x265pic_out->userData - 1;
         ReorderedData *rd = &ctx->rd[idx];
 
 #if FF_API_REORDERED_OPAQUE
