$NetBSD: patch-lib_mp4_smhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/smhd.c.orig	2017-09-25 14:55:33.725106695 +0000
+++ lib/mp4/smhd.c
@@ -3,7 +3,7 @@
 
 
 
-int quicktime_smhd_init(quicktime_smhd_t *smhd)
+void quicktime_smhd_init(quicktime_smhd_t *smhd)
 {
 	smhd->version = 0;
 	smhd->flags = 0;
@@ -11,20 +11,20 @@ int quicktime_smhd_init(quicktime_smhd_t
 	smhd->reserved = 0;
 }
 
-int quicktime_smhd_delete(quicktime_smhd_t *smhd)
+void quicktime_smhd_delete(quicktime_smhd_t *smhd)
 {
 }
 
-int quicktime_smhd_dump(quicktime_smhd_t *smhd)
+void quicktime_smhd_dump(quicktime_smhd_t *smhd)
 {
 	printf("    sound media header\n");
 	printf("     version %d\n", smhd->version);
-	printf("     flags %d\n", smhd->flags);
+	printf("     flags %ld\n", smhd->flags);
 	printf("     balance %d\n", smhd->balance);
 	printf("     reserved %d\n", smhd->reserved);
 }
 
-int quicktime_read_smhd(quicktime_t *file, quicktime_smhd_t *smhd)
+void quicktime_read_smhd(quicktime_t *file, quicktime_smhd_t *smhd)
 {
 	smhd->version = quicktime_read_char(file);
 	smhd->flags = quicktime_read_int24(file);
@@ -32,7 +32,7 @@ int quicktime_read_smhd(quicktime_t *fil
 	smhd->reserved = quicktime_read_int16(file);
 }
 
-int quicktime_write_smhd(quicktime_t *file, quicktime_smhd_t *smhd)
+void quicktime_write_smhd(quicktime_t *file, quicktime_smhd_t *smhd)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "smhd");
