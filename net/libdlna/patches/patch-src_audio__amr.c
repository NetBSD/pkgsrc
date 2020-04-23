$NetBSD: patch-src_audio__amr.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/audio_amr.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/audio_amr.c
@@ -53,7 +53,7 @@ audio_is_valid_amr (AVCodecContext *ac)
   if (!ac)
     return 0;
 
-  if (ac->codec_id != CODEC_ID_AMR_NB)
+  if (ac->codec_id != AV_CODEC_ID_AMR_NB)
     return 0;
   
   /* only mono is supported */
@@ -89,7 +89,7 @@ audio_is_valid_amr_wb (AVCodecContext *a
   if (!ac)
     return 0;
 
-  if (ac->codec_id != CODEC_ID_AMR_WB)
+  if (ac->codec_id != AV_CODEC_ID_AMR_WB)
     return 0;
   
   /* valid sampling rates: 8, 16, 24, 32 and 48 kHz */
