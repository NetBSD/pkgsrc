$NetBSD: patch-lib_mp4_mvhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/mvhd.c.orig	2017-09-25 14:55:49.237133276 +0000
+++ lib/mp4/mvhd.c
@@ -30,13 +30,13 @@ int quicktime_mvhd_delete(quicktime_mvhd
 	return 0;
 }
 
-int quicktime_mvhd_dump(quicktime_mvhd_t *mvhd)
+void quicktime_mvhd_dump(quicktime_mvhd_t *mvhd)
 {
 	printf(" movie header\n");
 	printf("  version %d\n", mvhd->version);
 	printf("  flags %ld\n", mvhd->flags);
-	printf("  creation_time %u\n", mvhd->creation_time);
-	printf("  modification_time %u\n", mvhd->modification_time);
+	printf("  creation_time %lu\n", mvhd->creation_time);
+	printf("  modification_time %lu\n", mvhd->modification_time);
 	printf("  time_scale %ld\n", mvhd->time_scale);
 	printf("  duration %ld\n", mvhd->duration);
 	printf("  preferred_rate %f\n", mvhd->preferred_rate);
@@ -52,7 +52,7 @@ int quicktime_mvhd_dump(quicktime_mvhd_t
 	printf("  next_track_id %ld\n", mvhd->next_track_id);
 }
 
-int quicktime_read_mvhd(quicktime_t *file, quicktime_mvhd_t *mvhd)
+void quicktime_read_mvhd(quicktime_t *file, quicktime_mvhd_t *mvhd)
 {
 	mvhd->version = quicktime_read_char(file);
 	mvhd->flags = quicktime_read_int24(file);
@@ -73,7 +73,7 @@ int quicktime_read_mvhd(quicktime_t *fil
 	mvhd->next_track_id = quicktime_read_int32(file);
 }
 
-int quicktime_write_mvhd(quicktime_t *file, quicktime_mvhd_t *mvhd)
+void quicktime_write_mvhd(quicktime_t *file, quicktime_mvhd_t *mvhd)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "mvhd");
