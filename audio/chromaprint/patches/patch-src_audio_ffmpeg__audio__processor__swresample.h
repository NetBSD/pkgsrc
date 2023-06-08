$NetBSD: patch-src_audio_ffmpeg__audio__processor__swresample.h,v 1.1 2023/06/08 07:05:18 wiz Exp $

Support ffmpeg5
https://github.com/acoustid/chromaprint/pull/120/files

--- src/audio/ffmpeg_audio_processor_swresample.h.orig	2021-12-23 05:57:54.000000000 +0000
+++ src/audio/ffmpeg_audio_processor_swresample.h
@@ -28,30 +28,28 @@ public:
 		av_opt_set_double(m_swr_ctx, "cutoff", 0.8, 0);
 	}
 
-	void SetInputChannelLayout(int64_t channel_layout) {
-		av_opt_set_int(m_swr_ctx, "icl", channel_layout, 0);
-		av_opt_set_int(m_swr_ctx, "ich", av_get_channel_layout_nb_channels(channel_layout), 0);
+	void SetInputChannelLayout(AVChannelLayout *channel_layout) {
+		av_opt_set_int(m_swr_ctx, "in_channel_layout", channel_layout->u.mask, 0);
 	}
 
 	void SetInputSampleFormat(AVSampleFormat sample_format) {
-		av_opt_set_int(m_swr_ctx, "isf", sample_format, 0);
+		av_opt_set_sample_fmt(m_swr_ctx, "in_sample_fmt", sample_format, 0);
 	}
 
 	void SetInputSampleRate(int sample_rate) {
-		av_opt_set_int(m_swr_ctx, "isr", sample_rate, 0);
+		av_opt_set_int(m_swr_ctx, "in_sample_rate", sample_rate, 0);
 	}
 
-	void SetOutputChannelLayout(int64_t channel_layout) {
-		av_opt_set_int(m_swr_ctx, "ocl", channel_layout, 0);
-		av_opt_set_int(m_swr_ctx, "och", av_get_channel_layout_nb_channels(channel_layout), 0);
+	void SetOutputChannelLayout(AVChannelLayout *channel_layout) {
+		av_opt_set_int(m_swr_ctx, "out_channel_layout", channel_layout->u.mask, 0);
 	}
 
 	void SetOutputSampleFormat(AVSampleFormat sample_format) {
-		av_opt_set_int(m_swr_ctx, "osf", sample_format, 0);
+		av_opt_set_sample_fmt(m_swr_ctx, "out_sample_fmt", sample_format, 0);
 	}
 
 	void SetOutputSampleRate(int sample_rate) {
-		av_opt_set_int(m_swr_ctx, "osr", sample_rate, 0);
+		av_opt_set_int(m_swr_ctx, "out_sample_rate", sample_rate, 0);
 	}
 
 	int Init() {
