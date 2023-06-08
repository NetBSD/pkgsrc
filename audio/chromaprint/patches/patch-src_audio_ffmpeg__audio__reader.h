$NetBSD: patch-src_audio_ffmpeg__audio__reader.h,v 1.1 2023/06/08 07:05:18 wiz Exp $

Support ffmpeg5
https://github.com/acoustid/chromaprint/pull/120/files

--- src/audio/ffmpeg_audio_reader.h.orig	2021-12-23 05:57:54.000000000 +0000
+++ src/audio/ffmpeg_audio_reader.h
@@ -62,7 +62,7 @@ public:
 	bool Read(const int16_t **data, size_t *size);
 
 	bool IsOpen() const { return m_opened; }
-	bool IsFinished() const { return m_finished && !m_got_frame; }
+	bool IsFinished() const { return !m_has_more_packets && !m_has_more_frames; }
 
 	std::string GetError() const { return m_error; }
 	int GetErrorCode() const { return m_error_code; }
@@ -74,20 +74,19 @@ private:
 	uint8_t *m_convert_buffer[1] = { nullptr };
 	int m_convert_buffer_nb_samples = 0;
 
-	AVInputFormat *m_input_fmt = nullptr;
+	const AVInputFormat *m_input_fmt = nullptr;
 	AVDictionary *m_input_opts = nullptr;
 
 	AVFormatContext *m_format_ctx = nullptr;
 	AVCodecContext *m_codec_ctx = nullptr;
-	AVFrame *m_frame = nullptr;
 	int m_stream_index = -1;
 	std::string m_error;
 	int m_error_code = 0;
-	bool m_finished = false;
 	bool m_opened = false;
-	int m_got_frame = 0;
-	AVPacket m_packet;
-	AVPacket m_packet0;
+	bool m_has_more_packets = true;
+	bool m_has_more_frames = true;
+	AVPacket *m_packet = nullptr;
+	AVFrame *m_frame = nullptr;
 
 	int m_output_sample_rate = 0;
 	int m_output_channels = 0;
@@ -98,19 +97,12 @@ private:
 
 inline FFmpegAudioReader::FFmpegAudioReader() {
 	av_log_set_level(AV_LOG_QUIET);
-
-	av_init_packet(&m_packet);
-	m_packet.data = nullptr;
-	m_packet.size = 0;
-
-	m_packet0 = m_packet;
 }
 
 inline FFmpegAudioReader::~FFmpegAudioReader() {
 	Close();
 	av_dict_free(&m_input_opts);
 	av_freep(&m_convert_buffer[0]);
-	av_packet_unref(&m_packet0);
 }
 
 inline bool FFmpegAudioReader::SetInputFormat(const char *name) {
@@ -135,11 +127,10 @@ inline bool FFmpegAudioReader::Open(cons
 
 	Close();
 
-    av_init_packet(&m_packet);
-	m_packet.data = nullptr;
-	m_packet.size = 0;
-
-	m_packet0 = m_packet;
+	m_packet = av_packet_alloc();
+	if (!m_packet) {
+		return false;
+	}
 
 	ret = avformat_open_input(&m_format_ctx, file_name.c_str(), m_input_fmt, &m_input_opts);
 	if (ret < 0) {
@@ -153,26 +144,31 @@ inline bool FFmpegAudioReader::Open(cons
 		return false;
 	}
 
-	AVCodec *codec;
+	const AVCodec *codec;
 	ret = av_find_best_stream(m_format_ctx, AVMEDIA_TYPE_AUDIO, -1, -1, &codec, 0);
 	if (ret < 0) {
 		SetError("Could not find any audio stream in the file", ret);
 		return false;
 	}
 	m_stream_index = ret;
+	auto stream = m_format_ctx->streams[m_stream_index];
 
-	m_codec_ctx = m_format_ctx->streams[m_stream_index]->codec;
+	m_codec_ctx = avcodec_alloc_context3(codec);
 	m_codec_ctx->request_sample_fmt = AV_SAMPLE_FMT_S16;
 
+	ret = avcodec_parameters_to_context(m_codec_ctx, stream->codecpar);
+	if (ret < 0) {
+		SetError("Could not copy the stream parameters", ret);
+		return false;
+	}
+
 	ret = avcodec_open2(m_codec_ctx, codec, nullptr);
 	if (ret < 0) {
 		SetError("Could not open the codec", ret);
 		return false;
 	}
 
-	if (!m_codec_ctx->channel_layout) {
-		m_codec_ctx->channel_layout = av_get_default_channel_layout(m_codec_ctx->channels);
-	}
+	av_dump_format(m_format_ctx, 0, "foo", 0);
 
 	m_frame = av_frame_alloc();
 	if (!m_frame) {
@@ -183,19 +179,23 @@ inline bool FFmpegAudioReader::Open(cons
 		m_output_sample_rate = m_codec_ctx->sample_rate;
 	}
 
-	if (!m_output_channels) {
-		m_output_channels = m_codec_ctx->channels;
+	AVChannelLayout output_channel_layout;
+	if (m_output_channels) {
+		av_channel_layout_default(&output_channel_layout, m_output_channels);
+	} else {
+		m_output_channels = m_codec_ctx->ch_layout.nb_channels;
+		av_channel_layout_default(&output_channel_layout, m_output_channels);
 	}
 
-	if (m_codec_ctx->sample_fmt != AV_SAMPLE_FMT_S16 || m_codec_ctx->channels != m_output_channels || m_codec_ctx->sample_rate != m_output_sample_rate) {
+	if (m_codec_ctx->sample_fmt != AV_SAMPLE_FMT_S16 || m_codec_ctx->ch_layout.nb_channels != m_output_channels || m_codec_ctx->sample_rate != m_output_sample_rate) {
 		m_converter.reset(new FFmpegAudioProcessor());
 		m_converter->SetCompatibleMode();
 		m_converter->SetInputSampleFormat(m_codec_ctx->sample_fmt);
 		m_converter->SetInputSampleRate(m_codec_ctx->sample_rate);
-		m_converter->SetInputChannelLayout(m_codec_ctx->channel_layout);
+		m_converter->SetInputChannelLayout(&(m_codec_ctx->ch_layout));
 		m_converter->SetOutputSampleFormat(AV_SAMPLE_FMT_S16);
 		m_converter->SetOutputSampleRate(m_output_sample_rate);
-		m_converter->SetOutputChannelLayout(av_get_default_channel_layout(m_output_channels));
+		m_converter->SetOutputChannelLayout(&output_channel_layout);
 		auto ret = m_converter->Init();
 		if (ret != 0) {
 			SetError("Could not create an audio converter instance", ret);
@@ -203,10 +203,11 @@ inline bool FFmpegAudioReader::Open(cons
 		}
 	}
 
+	av_channel_layout_uninit(&output_channel_layout);
+
 	m_opened = true;
-	m_finished = false;
-	m_got_frame = 0;
-	m_nb_packets = 0;
+	m_has_more_packets = true;
+	m_has_more_frames = true;
 	m_decode_error = 0;
 
 	return true;
@@ -214,6 +215,7 @@ inline bool FFmpegAudioReader::Open(cons
 
 inline void FFmpegAudioReader::Close() {
 	av_frame_free(&m_frame);
+	av_packet_free(&m_packet);
 
 	m_stream_index = -1;
 
@@ -252,91 +254,98 @@ inline bool FFmpegAudioReader::Read(cons
 		return false;
 	}
 
+	*data = nullptr;
+	*size = 0;
+
 	int ret;
+	bool needs_packet = false;
 	while (true) {
-		while (m_packet.size <= 0) {
-			av_packet_unref(&m_packet0);
-			av_init_packet(&m_packet);
-			m_packet.data = nullptr;
-			m_packet.size = 0;
-			ret = av_read_frame(m_format_ctx, &m_packet);
+		while (needs_packet && m_packet->size == 0) {
+			ret = av_read_frame(m_format_ctx, m_packet);
 			if (ret < 0) {
 				if (ret == AVERROR_EOF) {
-					m_finished = true;
+					needs_packet = false;
+					m_has_more_packets = false;
 					break;
-				} else {
+				}
+				SetError("Error reading from the audio source", ret);
+				return false;
+			}
+			if (m_packet->stream_index == m_stream_index) {
+				needs_packet = false;
+			} else {
+				av_packet_unref(m_packet);
+			}
+		}
+
+		if (m_packet->size != 0) {
+			ret = avcodec_send_packet(m_codec_ctx, m_packet);
+			if (ret < 0) {
+				if (ret != AVERROR(EAGAIN)) {
 					SetError("Error reading from the audio source", ret);
 					return false;
 				}
-			}
-			m_packet0 = m_packet;
-			if (m_packet.stream_index != m_stream_index) {
-				m_packet.data = nullptr;
-				m_packet.size = 0;
 			} else {
-				m_nb_packets++;
+				av_packet_unref(m_packet);
 			}
 		}
 
-		ret = avcodec_decode_audio4(m_codec_ctx, m_frame, &m_got_frame, &m_packet);
+		ret = avcodec_receive_frame(m_codec_ctx, m_frame);
 		if (ret < 0) {
-			if (m_decode_error) {
-				SetError("Error decoding audio frame", m_decode_error);
-				return false;
+			if (ret == AVERROR_EOF) {
+				m_has_more_frames = false;
+			} else if (ret == AVERROR(EAGAIN)) {
+				if (m_has_more_packets) {
+					needs_packet = true;
+					continue;
+				} else {
+					m_has_more_frames = false;
+				}
 			}
-			m_decode_error = ret;
-			m_packet.data = nullptr;
-			m_packet.size = 0;
-			continue;
+			SetError("Error decoding the audio source", ret);
+			return false;
 		}
 
-		break;
-	}
-
-	m_decode_error = 0;
-
-	const int decoded = std::min(ret, m_packet.size);
-	m_packet.data += decoded;
-	m_packet.size -= decoded;
-
-	if (m_got_frame) {
-		if (m_converter) {
-			if (m_frame->nb_samples > m_convert_buffer_nb_samples) {
-				int linsize;
-				av_freep(&m_convert_buffer[0]);
-				m_convert_buffer_nb_samples = std::max(1024 * 8, m_frame->nb_samples);
-				ret = av_samples_alloc(m_convert_buffer, &linsize, m_codec_ctx->channels, m_convert_buffer_nb_samples, AV_SAMPLE_FMT_S16, 1);
-				if (ret < 0) {
-					SetError("Couldn't allocate audio converter buffer", ret);
+		if (m_frame->nb_samples > 0) {
+			if (m_converter) {
+				if (m_frame->nb_samples > m_convert_buffer_nb_samples) {
+					int linsize;
+					av_freep(&m_convert_buffer[0]);
+					m_convert_buffer_nb_samples = std::max(1024 * 8, m_frame->nb_samples);
+					ret = av_samples_alloc(m_convert_buffer, &linsize, m_codec_ctx->ch_layout.nb_channels, m_convert_buffer_nb_samples, AV_SAMPLE_FMT_S16, 1);
+					if (ret < 0) {
+						SetError("Couldn't allocate audio converter buffer", ret);
+						return false;
+					}
+				}
+				auto nb_samples = m_converter->Convert(m_convert_buffer, m_convert_buffer_nb_samples, (const uint8_t **) m_frame->data, m_frame->nb_samples);
+				if (nb_samples < 0) {
+					SetError("Couldn't convert audio", ret);
 					return false;
 				}
-			}
-			auto nb_samples = m_converter->Convert(m_convert_buffer, m_convert_buffer_nb_samples, (const uint8_t **) m_frame->data, m_frame->nb_samples);
-			if (nb_samples < 0) {
-				SetError("Couldn't convert audio", ret);
-				return false;
-			}
-			*data = (const int16_t *) m_convert_buffer[0];
-			*size = nb_samples;
-		} else {
-			*data = (const int16_t *) m_frame->data[0];
-			*size = m_frame->nb_samples;
-		}
-	} else {
-		if (m_finished && m_converter) {
-			auto nb_samples = m_converter->Flush(m_convert_buffer, m_convert_buffer_nb_samples);
-			if (nb_samples < 0) {
-				SetError("Couldn't convert audio", ret);
-				return false;
-			} else if (nb_samples > 0) {
-				m_got_frame = 1;
 				*data = (const int16_t *) m_convert_buffer[0];
 				*size = nb_samples;
+			} else {
+				*data = (const int16_t *) m_frame->data[0];
+				*size = m_frame->nb_samples;
+			}
+		} else {
+			if (m_converter) {
+				if (IsFinished()) {
+					auto nb_samples = m_converter->Flush(m_convert_buffer, m_convert_buffer_nb_samples);
+					if (nb_samples < 0) {
+						SetError("Couldn't convert audio", ret);
+						return false;
+					} else if (nb_samples > 0) {
+						*data = (const int16_t *) m_convert_buffer[0];
+						*size = nb_samples;
+					}
+				}
 			}
 		}
-	}
 
-	return true;
+		return true;
+	}
 }
 
 inline void FFmpegAudioReader::SetError(const char *message, int errnum) {
