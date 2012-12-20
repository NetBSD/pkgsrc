$NetBSD: patch-lib_mp4_trak.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/trak.c.orig	2012-12-20 16:53:00.000000000 +0000
+++ lib/mp4/trak.c
@@ -178,6 +178,9 @@ int quicktime_read_trak(quicktime_t *fil
 	return 0;
 }
 
+void quicktime_write_hint_udta(quicktime_t *file, quicktime_hint_udta_t *hint_udta);
+void quicktime_write_tref(quicktime_t *file, quicktime_tref_t *tref);
+
 int quicktime_write_trak(quicktime_t *file, quicktime_trak_t *trak, long moov_time_scale)
 {
 	long duration;
