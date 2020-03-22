$NetBSD: patch-groove_encoder.c,v 1.1 2020/03/22 07:52:59 nia Exp $

Fix build with ffmpeg4.

--- groove/encoder.c.orig	2015-05-26 01:32:01.000000000 +0000
+++ groove/encoder.c
@@ -616,7 +616,7 @@ int groove_encoder_attach(struct GrooveE
 
     e->sink->audio_format = encoder->actual_audio_format;
     e->sink->buffer_size = encoder->sink_buffer_size;
-    e->sink->buffer_sample_count = (codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE) ?
+    e->sink->buffer_sample_count = (codec->capabilities & AV_CODEC_CAP_VARIABLE_FRAME_SIZE) ?
         0 : e->stream->codec->frame_size;
     e->sink->gain = encoder->gain;
 
