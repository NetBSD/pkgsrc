$NetBSD: patch-lib_mp4_quicktime.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/quicktime.c.orig	2017-09-25 14:55:41.219458342 +0000
+++ lib/mp4/quicktime.c
@@ -132,22 +132,22 @@ int quicktime_make_streamable(char *in_p
 	return 0;
 }
 
-int quicktime_set_time_scale(quicktime_t *file, int time_scale)
+void quicktime_set_time_scale(quicktime_t *file, int time_scale)
 {
 	file->moov.mvhd.time_scale = time_scale;
 }
 
-int quicktime_set_copyright(quicktime_t *file, char *string)
+void quicktime_set_copyright(quicktime_t *file, char *string)
 {
 	quicktime_set_udta_string(&(file->moov.udta.copyright), &(file->moov.udta.copyright_len), string);
 }
 
-int quicktime_set_name(quicktime_t *file, char *string)
+void quicktime_set_name(quicktime_t *file, char *string)
 {
 	quicktime_set_udta_string(&(file->moov.udta.name), &(file->moov.udta.name_len), string);
 }
 
-int quicktime_set_info(quicktime_t *file, char *string)
+void quicktime_set_info(quicktime_t *file, char *string)
 {
 	quicktime_set_udta_string(&(file->moov.udta.info), &(file->moov.udta.info_len), string);
 }
@@ -177,7 +177,7 @@ int quicktime_get_iod_audio_profile_leve
 	return file->moov.iods.audioProfileId;
 }
 
-int quicktime_set_iod_audio_profile_level(quicktime_t *file, int id)
+void quicktime_set_iod_audio_profile_level(quicktime_t *file, int id)
 {
 	quicktime_iods_set_audio_profile(&file->moov.iods, id);
 }
@@ -187,7 +187,7 @@ int quicktime_get_iod_video_profile_leve
 	return file->moov.iods.videoProfileId;
 }
 
-int quicktime_set_iod_video_profile_level(quicktime_t *file, int id)
+void quicktime_set_iod_video_profile_level(quicktime_t *file, int id)
 {
 	quicktime_iods_set_video_profile(&file->moov.iods, id);
 }
@@ -431,12 +431,12 @@ char* quicktime_get_session_sdp(quicktim
 	return file->moov.udta.hnti.rtp.string;
 }
 
-int quicktime_set_session_sdp(quicktime_t *file, char* sdpString)
+void quicktime_set_session_sdp(quicktime_t *file, char* sdpString)
 {
-	return quicktime_rtp_set(&(file->moov.udta.hnti.rtp), sdpString);
+	quicktime_rtp_set(&(file->moov.udta.hnti.rtp), sdpString);
 }
 
-int quicktime_add_audio_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack)
+void quicktime_add_audio_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack)
 {
 	quicktime_trak_t* hintTrak = 
 		file->atracks[track].hintTracks[hintTrack];
@@ -444,7 +444,7 @@ int quicktime_add_audio_sdp(quicktime_t 
 	quicktime_sdp_append(&(hintTrak->hint_udta.hnti.sdp), sdpString);
 }
 
-int quicktime_add_video_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack)
+void quicktime_add_video_sdp(quicktime_t *file, char* sdpString, int track, int hintTrack)
 {
 	quicktime_trak_t* hintTrak = 
 		file->vtracks[track].hintTracks[hintTrack];
@@ -486,7 +486,7 @@ int quicktime_set_video_hint_max_rate(qu
 		granularity, maxBitRate, hintTrak);
 }
 
-int quicktime_set_framerate(quicktime_t *file, float framerate)
+void quicktime_set_framerate(quicktime_t *file, float framerate)
 {
 	int i;
 	int new_time_scale, new_sample_duration;
@@ -557,7 +557,7 @@ int quicktime_set_cpus(quicktime_t *file
 	return 0;
 }
 
-int quicktime_set_preload(quicktime_t *file, long preload)
+void quicktime_set_preload(quicktime_t *file, long preload)
 {
 	if(!file->preload_size)
 	{
@@ -801,7 +801,7 @@ int quicktime_video_depth(quicktime_t *f
 	return 0;
 }
 
-int quicktime_set_depth(quicktime_t *file, int depth, int track)
+void quicktime_set_depth(quicktime_t *file, int depth, int track)
 {
 	int i;
 
