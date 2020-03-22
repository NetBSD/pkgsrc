$NetBSD: patch-groove_playlist.c,v 1.1 2020/03/22 07:52:59 nia Exp $

Fix build with ffmpeg4.

--- groove/playlist.c.orig	2015-05-26 01:32:01.000000000 +0000
+++ groove/playlist.c
@@ -186,7 +186,7 @@ static int audio_decode_frame(struct Gro
 
         if (!got_frame) {
             // stop sending empty packets if the decoder is finished
-            if (!pkt_temp->data && dec->codec->capabilities & CODEC_CAP_DELAY)
+            if (!pkt_temp->data && dec->codec->capabilities & AV_CODEC_CAP_DELAY)
                 return 0;
             continue;
         }
@@ -571,7 +571,7 @@ static int decode_one_frame(struct Groov
     pthread_mutex_unlock(&f->seek_mutex);
 
     if (f->eof) {
-        if (f->audio_st->codec->codec->capabilities & CODEC_CAP_DELAY) {
+        if (f->audio_st->codec->codec->capabilities & AV_CODEC_CAP_DELAY) {
             av_init_packet(pkt);
             pkt->data = NULL;
             pkt->size = 0;
