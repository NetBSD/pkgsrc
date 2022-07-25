$NetBSD: patch-av__helpers.c,v 1.1 2022/07/25 00:45:05 tnn Exp $

Fix build with FFmpeg 5.1.
struct AVCodec.decode was removed in: 
https://github.com/FFmpeg/FFmpeg/commit/20f972701806be20a77f808db332d9489343bb78

--- av_helpers.c.orig	2021-05-01 17:45:31.000000000 +0000
+++ av_helpers.c
@@ -51,11 +51,9 @@ static void mp_msp_av_log_callback(void 
             AVCodecContext *s= ptr;
             if(s->codec){
                 if(s->codec->type == AVMEDIA_TYPE_AUDIO){
-                    if(s->codec->decode)
-                        type= MSGT_DECAUDIO;
+                    type= MSGT_DECAUDIO;
                 }else if(s->codec->type == AVMEDIA_TYPE_VIDEO){
-                    if(s->codec->decode)
-                        type= MSGT_DECVIDEO;
+                    type= MSGT_DECVIDEO;
                 }
                 //FIXME subtitles, encoders (what msgt for them? there is no appropriate ...)
             }
