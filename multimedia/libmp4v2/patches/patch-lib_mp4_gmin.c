$NetBSD: patch-lib_mp4_gmin.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/gmin.c.orig	2017-09-25 14:53:09.783132407 +0000
+++ lib/mp4/gmin.c
@@ -3,7 +3,7 @@
 
 
 
-int quicktime_gmin_init(quicktime_gmin_t *gmin)
+void quicktime_gmin_init(quicktime_gmin_t *gmin)
 {
 	gmin->version = 0;
 	gmin->flags = 0;
@@ -15,22 +15,22 @@ int quicktime_gmin_init(quicktime_gmin_t
 	gmin->reserved = 0;
 }
 
-int quicktime_gmin_delete(quicktime_gmin_t *gmin)
+void quicktime_gmin_delete(quicktime_gmin_t *gmin)
 {
 }
 
-int quicktime_gmin_dump(quicktime_gmin_t *gmin)
+void quicktime_gmin_dump(quicktime_gmin_t *gmin)
 {
 	printf("     generic media info\n");
 	printf("      version %d\n", gmin->version);
-	printf("      flags %d\n", gmin->flags);
+	printf("      flags %ld\n", gmin->flags);
 	printf("      graphics_mode %d\n", gmin->graphics_mode);
 	printf("      opcolor %d %d %d\n", gmin->opcolor[0], gmin->opcolor[1], gmin->opcolor[2]);
 	printf("      balance %d\n", gmin->balance);
 	printf("      reserved %d\n", gmin->reserved);
 }
 
-int quicktime_read_gmin(quicktime_t *file, quicktime_gmin_t *gmin)
+void quicktime_read_gmin(quicktime_t *file, quicktime_gmin_t *gmin)
 {
 	int i;
 
@@ -43,7 +43,7 @@ int quicktime_read_gmin(quicktime_t *fil
 	gmin->reserved = quicktime_read_int16(file);
 }
 
-int quicktime_write_gmin(quicktime_t *file, quicktime_gmin_t *gmin)
+void quicktime_write_gmin(quicktime_t *file, quicktime_gmin_t *gmin)
 {
 	int i;
 	quicktime_atom_t atom;
