$NetBSD: patch-decoder__plugins_ffmpeg_ffmpeg.c,v 1.1 2025/02/19 16:55:16 adam Exp $

Fix build with FFmpeg 4.

--- decoder_plugins/ffmpeg/ffmpeg.c.orig	2025-02-19 16:02:01.187401861 +0000
+++ decoder_plugins/ffmpeg/ffmpeg.c
@@ -993,8 +993,8 @@ static void *ffmpeg_open (const char *fi
 #endif
 
 	set_downmixing (data);
-	if (data->codec->capabilities & CODEC_CAP_TRUNCATED)
-		data->enc->flags |= CODEC_FLAG_TRUNCATED;
+	if (data->codec->capabilities & AV_CODEC_CAP_TRUNCATED)
+		data->enc->flags |= AV_CODEC_FLAG_TRUNCATED;
 
 #ifdef HAVE_AVCODEC_OPEN2
 	if (avcodec_open2 (data->enc, data->codec, NULL) < 0)
@@ -1025,7 +1025,7 @@ static void *ffmpeg_open (const char *fi
 
 	data->sample_width = sfmt_Bps (data->fmt);
 
-	if (data->codec->capabilities & CODEC_CAP_DELAY)
+	if (data->codec->capabilities & AV_CODEC_CAP_DELAY)
 		data->delay = true;
 	data->seek_broken = is_seek_broken (data);
 	data->timing_broken = is_timing_broken (data->ic);
