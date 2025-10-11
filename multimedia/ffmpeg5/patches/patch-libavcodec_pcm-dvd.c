$NetBSD: patch-libavcodec_pcm-dvd.c,v 1.1 2025/10/11 20:11:21 mrg Exp $

Port ffmpeg 7 change to satisfy GCC 14.


--- libavcodec/pcm-dvd.c.orig	2025-08-13 17:31:30.000000000 -0700
+++ libavcodec/pcm-dvd.c	2025-10-11 11:59:30.893893419 -0700
@@ -157,7 +157,7 @@ static void *pcm_dvd_decode_samples(AVCo
     switch (avctx->bits_per_coded_sample) {
     case 16: {
 #if HAVE_BIGENDIAN
-        bytestream2_get_buffer(&gb, dst16, blocks * s->block_size);
+        bytestream2_get_buffer(&gb, (uint8_t*)dst16, blocks * s->block_size);
         dst16 += blocks * s->block_size / 2;
 #else
         int samples = blocks * avctx->ch_layout.nb_channels;
