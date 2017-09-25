$NetBSD: patch-lib_mp4_mdhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/mdhd.c.orig	2017-09-25 14:54:56.041582738 +0000
+++ lib/mp4/mdhd.c
@@ -1,6 +1,6 @@
 #include "quicktime.h"
 
-int quicktime_mdhd_init(quicktime_mdhd_t *mdhd)
+void quicktime_mdhd_init(quicktime_mdhd_t *mdhd)
 {
 	mdhd->version = 0;
 	mdhd->flags = 0;
@@ -12,7 +12,7 @@ int quicktime_mdhd_init(quicktime_mdhd_t
 	mdhd->quality = 0;
 }
 
-int quicktime_mdhd_init_video(quicktime_t *file, 
+void quicktime_mdhd_init_video(quicktime_t *file, 
 							quicktime_mdhd_t *mdhd,
 							int time_scale)
 {
@@ -20,7 +20,7 @@ int quicktime_mdhd_init_video(quicktime_
 	mdhd->duration = 0;      /* set this when closing */
 }
 
-int quicktime_mdhd_init_audio(quicktime_t *file, 
+void quicktime_mdhd_init_audio(quicktime_t *file, 
 							quicktime_mdhd_t *mdhd, 
 							int time_scale)
 {
@@ -28,7 +28,7 @@ int quicktime_mdhd_init_audio(quicktime_
 	mdhd->duration = 0;      /* set this when closing */
 }
 
-int quicktime_mdhd_init_hint(quicktime_t *file, 
+void quicktime_mdhd_init_hint(quicktime_t *file, 
 							quicktime_mdhd_t *mdhd, 
 							quicktime_trak_t *refTrak,
 							int time_scale)
@@ -39,11 +39,11 @@ int quicktime_mdhd_init_hint(quicktime_t
 	mdhd->language = refTrak->mdia.mdhd.language;
 }
 
-quicktime_mdhd_delete(quicktime_mdhd_t *mdhd)
+void quicktime_mdhd_delete(quicktime_mdhd_t *mdhd)
 {
 }
 
-int quicktime_read_mdhd(quicktime_t *file, quicktime_mdhd_t *mdhd)
+void quicktime_read_mdhd(quicktime_t *file, quicktime_mdhd_t *mdhd)
 {
 	mdhd->version = quicktime_read_char(file);
 	mdhd->flags = quicktime_read_int24(file);
@@ -55,20 +55,20 @@ int quicktime_read_mdhd(quicktime_t *fil
 	mdhd->quality = quicktime_read_int16(file);
 }
 
-int quicktime_mdhd_dump(quicktime_mdhd_t *mdhd)
+void quicktime_mdhd_dump(quicktime_mdhd_t *mdhd)
 {
 	printf("   media header\n");
 	printf("    version %d\n", mdhd->version);
-	printf("    flags %d\n", mdhd->flags);
-	printf("    creation_time %u\n", mdhd->creation_time);
-	printf("    modification_time %u\n", mdhd->modification_time);
-	printf("    time_scale %d\n", mdhd->time_scale);
-	printf("    duration %d\n", mdhd->duration);
+	printf("    flags %ld\n", mdhd->flags);
+	printf("    creation_time %lu\n", mdhd->creation_time);
+	printf("    modification_time %lu\n", mdhd->modification_time);
+	printf("    time_scale %ld\n", mdhd->time_scale);
+	printf("    duration %ld\n", mdhd->duration);
 	printf("    language %d\n", mdhd->language);
 	printf("    quality %d\n", mdhd->quality);
 }
 
-int quicktime_write_mdhd(quicktime_t *file, quicktime_mdhd_t *mdhd)
+void quicktime_write_mdhd(quicktime_t *file, quicktime_mdhd_t *mdhd)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "mdhd");
