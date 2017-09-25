$NetBSD: patch-lib_mp4_hmhd.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/hmhd.c.orig	2017-09-25 14:53:53.102877442 +0000
+++ lib/mp4/hmhd.c
@@ -22,7 +22,7 @@
 #include "quicktime.h"
 
 
-int quicktime_hmhd_init(quicktime_hmhd_t *hmhd)
+void quicktime_hmhd_init(quicktime_hmhd_t *hmhd)
 {
 	hmhd->version = 0;
 	hmhd->flags = 0;
@@ -33,23 +33,23 @@ int quicktime_hmhd_init(quicktime_hmhd_t
 	hmhd->slidingavgbitrate = 0;
 }
 
-int quicktime_hmhd_delete(quicktime_hmhd_t *hmhd)
+void quicktime_hmhd_delete(quicktime_hmhd_t *hmhd)
 {
 }
 
-int quicktime_hmhd_dump(quicktime_hmhd_t *hmhd)
+void quicktime_hmhd_dump(quicktime_hmhd_t *hmhd)
 {
 	printf("    hint media header\n");
 	printf("     version %d\n", hmhd->version);
-	printf("     flags %d\n", hmhd->flags);
+	printf("     flags %ld\n", hmhd->flags);
 	printf("     maxPDUsize %d\n", hmhd->maxPDUsize);
 	printf("     avgPDUsize %d\n", hmhd->avgPDUsize);
-	printf("     maxbitrate %d\n", hmhd->maxbitrate);
-	printf("     avgbitrate %d\n", hmhd->avgbitrate);
-	printf("     slidingavgbitrate %d\n", hmhd->slidingavgbitrate);
+	printf("     maxbitrate %ld\n", hmhd->maxbitrate);
+	printf("     avgbitrate %ld\n", hmhd->avgbitrate);
+	printf("     slidingavgbitrate %ld\n", hmhd->slidingavgbitrate);
 }
 
-int quicktime_read_hmhd(quicktime_t *file, quicktime_hmhd_t *hmhd)
+void quicktime_read_hmhd(quicktime_t *file, quicktime_hmhd_t *hmhd)
 {
 	int i;
 	hmhd->version = quicktime_read_char(file);
@@ -61,7 +61,7 @@ int quicktime_read_hmhd(quicktime_t *fil
 	hmhd->slidingavgbitrate = quicktime_read_int32(file);
 }
 
-int quicktime_write_hmhd(quicktime_t *file, quicktime_hmhd_t *hmhd)
+void quicktime_write_hmhd(quicktime_t *file, quicktime_hmhd_t *hmhd)
 {
 	quicktime_atom_t atom;
 	int i;
