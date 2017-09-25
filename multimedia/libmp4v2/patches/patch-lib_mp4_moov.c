$NetBSD: patch-lib_mp4_moov.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/moov.c.orig	2017-09-25 14:55:51.205340295 +0000
+++ lib/mp4/moov.c
@@ -28,7 +28,7 @@ int quicktime_moov_delete(quicktime_moov
 	return 0;
 }
 
-int quicktime_moov_dump(quicktime_moov_t *moov)
+void quicktime_moov_dump(quicktime_moov_t *moov)
 {
 	int i;
 	printf("movie\n");
@@ -91,7 +91,7 @@ int quicktime_read_moov(quicktime_t *fil
 	return 0;
 }
 
-int quicktime_write_moov(quicktime_t *file, quicktime_moov_t *moov)
+void quicktime_write_moov(quicktime_t *file, quicktime_moov_t *moov)
 {
 	quicktime_atom_t atom;
 	int i;
@@ -128,7 +128,7 @@ int quicktime_write_moov(quicktime_t *fi
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_update_durations(quicktime_moov_t *moov)
+void quicktime_update_durations(quicktime_moov_t *moov)
 {
 	
 }
