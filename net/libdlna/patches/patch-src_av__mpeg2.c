$NetBSD: patch-src_av__mpeg2.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/av_mpeg2.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/av_mpeg2.c
@@ -453,7 +453,7 @@ probe_mpeg_ts (AVFormatContext *ctx,
   int i;
   
   /* check for MPEG-2 MP@LL profile */
-  if (codecs->ac->codec_id == CODEC_ID_AAC)
+  if (codecs->ac->codec_id == AV_CODEC_ID_AAC)
   {
     /* 352x288 only */
     if (codecs->vc->width != 352 && codecs->vc->height != 288)
@@ -535,7 +535,7 @@ probe_mpeg_ts (AVFormatContext *ctx,
   if (ctx->bit_rate > 19392700)
     return NULL;
 
-  if (codecs->ac->codec_id != CODEC_ID_AC3)
+  if (codecs->ac->codec_id != AV_CODEC_ID_AC3)
     return NULL;
 
   /* 48 KHz only */
@@ -615,7 +615,7 @@ probe_mpeg2 (AVFormatContext *ctx,
     return NULL;
   
   /* check for MPEG-2 video codec */
-  if (codecs->vc->codec_id != CODEC_ID_MPEG2VIDEO)
+  if (codecs->vc->codec_id != AV_CODEC_ID_MPEG2VIDEO)
     return NULL;
 
   switch (st)
