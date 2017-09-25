$NetBSD: patch-lib_mp4_quicktime.h,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/quicktime.h.orig	2017-09-25 15:14:46.164094744 +0000
+++ lib/mp4/quicktime.h
@@ -82,10 +82,10 @@ quicktime_t* quicktime_open(char *filena
 int quicktime_make_streamable(char *in_path, char *out_path);
 
 /* Set various options in the file. */
-int quicktime_set_time_scale(quicktime_t *file, int time_scale);
-int quicktime_set_copyright(quicktime_t *file, char *string);
-int quicktime_set_name(quicktime_t *file, char *string);
-int quicktime_set_info(quicktime_t *file, char *string);
+void quicktime_set_time_scale(quicktime_t *file, int time_scale);
+void quicktime_set_copyright(quicktime_t *file, char *string);
+void quicktime_set_name(quicktime_t *file, char *string);
+void quicktime_set_info(quicktime_t *file, char *string);
 int quicktime_get_time_scale(quicktime_t *file);
 char* quicktime_get_copyright(quicktime_t *file);
 char* quicktime_get_name(quicktime_t *file);
@@ -104,7 +104,7 @@ int quicktime_set_audio(quicktime_t *fil
 int quicktime_set_audio_hint(quicktime_t *file, int track, char *payloadName, u_int* pPayloadNumber, int maxPktSize);
 
 /* Samplerate can be set after file is created */
-int quicktime_set_framerate(quicktime_t *file, float framerate);
+void quicktime_set_framerate(quicktime_t *file, float framerate);
 
 /* video is stored one layer per quicktime track */
 int quicktime_set_video(quicktime_t *file, int tracks, int frame_w, int frame_h, float frame_rate, int time_scale, char *compressor);
@@ -116,7 +116,7 @@ int quicktime_set_video_hint(quicktime_t
 int quicktime_set_jpeg(quicktime_t *file, int quality, int use_float);
 
 /* Set the depth of the track. */
-int quicktime_set_depth(quicktime_t *file, int depth, int track);
+void quicktime_set_depth(quicktime_t *file, int depth, int track);
 
 /* close the file and delete all the objects */
 int quicktime_write(quicktime_t *file);
@@ -156,9 +156,9 @@ int quicktime_video_frame_time(quicktime
 	long *start_time, int *duration);
 
 int quicktime_get_iod_audio_profile_level(quicktime_t *file);
-int quicktime_set_iod_audio_profile_level(quicktime_t *file, int id);
+void quicktime_set_iod_audio_profile_level(quicktime_t *file, int id);
 int quicktime_get_iod_video_profile_level(quicktime_t *file);
-int quicktime_set_iod_video_profile_level(quicktime_t *file, int id);
+void quicktime_set_iod_video_profile_level(quicktime_t *file, int id);
 
 int quicktime_get_mp4_video_decoder_config(quicktime_t *file, int track, u_char** ppBuf, int* pBufSize);
 int quicktime_set_mp4_video_decoder_config(quicktime_t *file, int track, u_char* pBuf, int bufSize);
@@ -166,11 +166,11 @@ int quicktime_get_mp4_audio_decoder_conf
 int quicktime_set_mp4_audio_decoder_config(quicktime_t *file, int track, u_char* pBuf, int bufSize);
 
 char* quicktime_get_session_sdp(quicktime_t *file);
-int quicktime_set_session_sdp(quicktime_t *file, char* sdpString);
+void quicktime_set_session_sdp(quicktime_t *file, char* sdpString);
 
-int quicktime_add_audio_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack);
+void quicktime_add_audio_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack);
 
-int quicktime_add_video_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack);
+void quicktime_add_video_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack);
 
 int quicktime_set_audio_hint_max_rate(quicktime_t *file, int granularity, int maxBitRate, int audioTrack, int hintTrack);
 
@@ -245,7 +245,7 @@ int quicktime_dump_hint_packet(u_char* h
 int quicktime_dump_hint_data(u_char* hintBuf);
 
 int quicktime_get_hint_size(u_char* hintBuf);
-int quicktime_get_hint_info(u_char* hintBuf, u_int hintBufSize, quicktime_hint_info_t* pHintInfo);
+void quicktime_get_hint_info(u_char* hintBuf, u_int hintBufSize, quicktime_hint_info_t* pHintInfo);
 
 /* ===================== Access to built in codecs follows. */
 
@@ -289,7 +289,7 @@ int quicktime_set_cpus(quicktime_t *file
 
 /* Specify whether to read contiguously or not. */
 /* preload is the number of bytes to read ahead. */
-int quicktime_set_preload(quicktime_t *file, long preload);
+void quicktime_set_preload(quicktime_t *file, long preload);
 
 /* Test the 32 bit overflow */
 int quicktime_test_position(quicktime_t *file);
