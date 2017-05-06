$NetBSD: patch-lib_mp4_funcprotos.h,v 1.1 2017/05/06 18:12:00 maya Exp $

Match new return types.

--- lib/mp4/funcprotos.h.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/funcprotos.h
@@ -67,8 +67,8 @@ int quicktime_trak_init(quicktime_trak_t
 int quicktime_trak_init_video(quicktime_t *file, quicktime_trak_t *trak, int frame_w, int frame_h, float frame_rate, int time_scale, char *compressor);
 int quicktime_trak_init_audio(quicktime_t *file, quicktime_trak_t *trak, int channels, int sample_rate, int bits, int sample_size, int time_scale, int sample_duration, char *compressor);
 int quicktime_trak_init_hint(quicktime_t *file, quicktime_trak_t *trak, quicktime_trak_t *refTrak, int maxPktSize, int time_scale, int sample_duration);
-int quicktime_tref_init(quicktime_tref_t *tref);
-int quicktime_tref_init_hint(quicktime_tref_t *tref, quicktime_trak_t *refTrak);
+void quicktime_tref_init(quicktime_tref_t *tref);
+void quicktime_tref_init_hint(quicktime_tref_t *tref, quicktime_trak_t *refTrak);
 int quicktime_udta_init(quicktime_udta_t *udta);
 int quicktime_mvhd_init(quicktime_mvhd_t *mvhd);
 int quicktime_moov_init(quicktime_moov_t *moov);
