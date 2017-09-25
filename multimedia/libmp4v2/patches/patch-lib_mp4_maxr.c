$NetBSD: patch-lib_mp4_maxr.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/maxr.c.orig	2017-09-25 14:54:50.509412271 +0000
+++ lib/mp4/maxr.c
@@ -22,30 +22,30 @@
 #include "quicktime.h"
 
 
-int quicktime_maxr_init(quicktime_maxr_t *maxr)
+void quicktime_maxr_init(quicktime_maxr_t *maxr)
 {
 	maxr->granularity = 0;
 	maxr->maxBitRate = 0;
 }
 
-int quicktime_maxr_delete(quicktime_maxr_t *maxr)
+void quicktime_maxr_delete(quicktime_maxr_t *maxr)
 {
 }
 
-int quicktime_maxr_dump(quicktime_maxr_t *maxr)
+void quicktime_maxr_dump(quicktime_maxr_t *maxr)
 {
 	printf("    max data rate\n");
-	printf("     granularity %lu\n", maxr->granularity);
-	printf("     maxBitRate %lu\n", maxr->maxBitRate);
+	printf("     granularity %u\n", (unsigned)maxr->granularity);
+	printf("     maxBitRate %u\n", (unsigned)maxr->maxBitRate);
 }
 
-int quicktime_read_maxr(quicktime_t *file, quicktime_maxr_t *maxr)
+void quicktime_read_maxr(quicktime_t *file, quicktime_maxr_t *maxr)
 {
 	maxr->granularity = quicktime_read_int32(file);
 	maxr->maxBitRate = quicktime_read_int32(file);
 }
 
-int quicktime_write_maxr(quicktime_t *file, quicktime_maxr_t *maxr)
+void quicktime_write_maxr(quicktime_t *file, quicktime_maxr_t *maxr)
 {
 	quicktime_atom_t atom;
 
