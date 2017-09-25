$NetBSD: patch-lib_mp4_dmed.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/dmed.c.orig	2017-09-25 14:52:16.963414472 +0000
+++ lib/mp4/dmed.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_dmed_init(quicktime_dmed_t *dmed)
+void quicktime_dmed_init(quicktime_dmed_t *dmed)
 {
 	dmed->numBytes = 0;
 }
 
-int quicktime_dmed_delete(quicktime_dmed_t *dmed)
+void quicktime_dmed_delete(quicktime_dmed_t *dmed)
 {
 }
 
-int quicktime_dmed_dump(quicktime_dmed_t *dmed)
+void quicktime_dmed_dump(quicktime_dmed_t *dmed)
 {
 	printf("    total media bytes\n");
 	printf("     numBytes "U64"\n", dmed->numBytes);
 }
 
-int quicktime_read_dmed(quicktime_t *file, quicktime_dmed_t *dmed)
+void quicktime_read_dmed(quicktime_t *file, quicktime_dmed_t *dmed)
 {
 	dmed->numBytes = quicktime_read_int64(file);
 }
 
-int quicktime_write_dmed(quicktime_t *file, quicktime_dmed_t *dmed)
+void quicktime_write_dmed(quicktime_t *file, quicktime_dmed_t *dmed)
 {
 	quicktime_atom_t atom;
 
