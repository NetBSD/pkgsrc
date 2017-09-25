$NetBSD: patch-lib_mp4_vmhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/vmhd.c.orig	2017-09-25 14:54:58.634007390 +0000
+++ lib/mp4/vmhd.c
@@ -1,7 +1,7 @@
 #include "quicktime.h"
 
 
-int quicktime_vmhd_init(quicktime_vmhd_t *vmhd)
+void quicktime_vmhd_init(quicktime_vmhd_t *vmhd)
 {
 	vmhd->version = 0;
 	vmhd->flags = 1;
@@ -11,7 +11,7 @@ int quicktime_vmhd_init(quicktime_vmhd_t
 	vmhd->opcolor[2] = 32768;
 }
 
-int quicktime_vmhd_init_video(quicktime_t *file, 
+void quicktime_vmhd_init_video(quicktime_t *file, 
 								quicktime_vmhd_t *vmhd, 
 								int frame_w,
 								int frame_h, 
@@ -19,20 +19,20 @@ int quicktime_vmhd_init_video(quicktime_
 {
 }
 
-int quicktime_vmhd_delete(quicktime_vmhd_t *vmhd)
+void quicktime_vmhd_delete(quicktime_vmhd_t *vmhd)
 {
 }
 
-int quicktime_vmhd_dump(quicktime_vmhd_t *vmhd)
+void quicktime_vmhd_dump(quicktime_vmhd_t *vmhd)
 {
 	printf("    video media header\n");
 	printf("     version %d\n", vmhd->version);
-	printf("     flags %d\n", vmhd->flags);
+	printf("     flags %ld\n", vmhd->flags);
 	printf("     graphics_mode %d\n", vmhd->graphics_mode);
 	printf("     opcolor %d %d %d\n", vmhd->opcolor[0], vmhd->opcolor[1], vmhd->opcolor[2]);
 }
 
-int quicktime_read_vmhd(quicktime_t *file, quicktime_vmhd_t *vmhd)
+void quicktime_read_vmhd(quicktime_t *file, quicktime_vmhd_t *vmhd)
 {
 	int i;
 	vmhd->version = quicktime_read_char(file);
@@ -42,7 +42,7 @@ int quicktime_read_vmhd(quicktime_t *fil
 		vmhd->opcolor[i] = quicktime_read_int16(file);
 }
 
-int quicktime_write_vmhd(quicktime_t *file, quicktime_vmhd_t *vmhd)
+void quicktime_write_vmhd(quicktime_t *file, quicktime_vmhd_t *vmhd)
 {
 	quicktime_atom_t atom;
 	int i;
