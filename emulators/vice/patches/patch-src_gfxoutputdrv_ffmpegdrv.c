$NetBSD: patch-src_gfxoutputdrv_ffmpegdrv.c,v 1.1 2012/10/10 13:40:06 drochner Exp $

Fix build with ffmpeg-0.10.

--- src/gfxoutputdrv/ffmpegdrv.c.orig	2011-02-14 17:20:56.000000000 +0000
+++ src/gfxoutputdrv/ffmpegdrv.c
@@ -342,7 +342,7 @@ static int ffmpegmovie_init_audio(int sp
 
     c = st->codec;
     c->codec_id = ffmpegdrv_fmt->audio_codec;
-    c->codec_type = CODEC_TYPE_AUDIO;
+    c->codec_type = AVMEDIA_TYPE_AUDIO;
     c->sample_fmt = SAMPLE_FMT_S16;
 
     /* put sample parameters */
@@ -370,7 +370,7 @@ static int ffmpegmovie_encode_audio(soun
         pkt.size = (*ffmpeglib.p_avcodec_encode_audio)(c, 
                         audio_outbuf, audio_outbuf_size, audio_in->buffer);
         pkt.pts = c->coded_frame->pts;
-        pkt.flags |= PKT_FLAG_KEY;
+        pkt.flags |= AV_PKT_FLAG_KEY;
         pkt.stream_index = audio_st->index;
         pkt.data = audio_outbuf;
 
@@ -559,7 +559,7 @@ static void ffmpegdrv_init_video(screens
 
     c = st->codec;
     c->codec_id = ffmpegdrv_fmt->video_codec;
-    c->codec_type = CODEC_TYPE_VIDEO;
+    c->codec_type = AVMEDIA_TYPE_VIDEO;
 
     /* put sample parameters */
     c->bit_rate = video_bitrate;
@@ -819,7 +819,7 @@ static int ffmpegdrv_record(screenshot_t
     if (ffmpegdrv_oc->oformat->flags & AVFMT_RAWPICTURE) {
         AVPacket pkt;
         (*ffmpeglib.p_av_init_packet)(&pkt);
-        pkt.flags |= PKT_FLAG_KEY;
+        pkt.flags |= AV_PKT_FLAG_KEY;
         pkt.stream_index = video_st->index;
         pkt.data = (uint8_t*)picture;
         pkt.size = sizeof(AVPicture);
@@ -840,7 +840,7 @@ static int ffmpegdrv_record(screenshot_t
             (*ffmpeglib.p_av_init_packet)(&pkt);
             pkt.pts = c->coded_frame->pts;
             if (c->coded_frame->key_frame)
-                pkt.flags |= PKT_FLAG_KEY;
+                pkt.flags |= AV_PKT_FLAG_KEY;
             pkt.stream_index = video_st->index;
             pkt.data = video_outbuf;
             pkt.size = out_size;
