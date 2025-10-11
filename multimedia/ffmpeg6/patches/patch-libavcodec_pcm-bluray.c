$NetBSD: patch-libavcodec_pcm-bluray.c,v 1.1 2025/10/11 20:11:21 mrg Exp $

Port ffmpeg 7 change to satisfy GCC 14.


--- libavcodec/pcm-bluray.c.orig	2025-08-14 16:31:16.000000000 -0700
+++ libavcodec/pcm-bluray.c	2025-09-14 12:20:04.000000000 -0700
@@ -167,7 +167,7 @@ static int pcm_bluray_decode_frame(AVCod
             samples *= num_source_channels;
             if (AV_SAMPLE_FMT_S16 == avctx->sample_fmt) {
 #if HAVE_BIGENDIAN
-                bytestream2_get_buffer(&gb, dst16, buf_size);
+                bytestream2_get_buffer(&gb, (uint8_t*)dst16, buf_size);
 #else
                 do {
                     *dst16++ = bytestream2_get_be16u(&gb);
@@ -187,7 +187,8 @@ static int pcm_bluray_decode_frame(AVCod
             if (AV_SAMPLE_FMT_S16 == avctx->sample_fmt) {
                 do {
 #if HAVE_BIGENDIAN
-                    bytestream2_get_buffer(&gb, dst16, avctx->ch_layout.nb_channels * 2);
+                    bytestream2_get_buffer(&gb, (uint8_t*)dst16,
+                                           avctx->ch_layout.nb_channels * 2);
                     dst16 += avctx->ch_layout.nb_channels;
 #else
                     channel = avctx->ch_layout.nb_channels;
