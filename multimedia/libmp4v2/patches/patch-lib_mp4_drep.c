$NetBSD: patch-lib_mp4_drep.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/drep.c.orig	2017-09-25 14:51:52.810957107 +0000
+++ lib/mp4/drep.c
@@ -22,27 +22,27 @@
 #include "quicktime.h"
 
 
-int quicktime_drep_init(quicktime_drep_t *drep)
+void quicktime_drep_init(quicktime_drep_t *drep)
 {
 	drep->numBytes = 0;
 }
 
-int quicktime_drep_delete(quicktime_drep_t *drep)
+void quicktime_drep_delete(quicktime_drep_t *drep)
 {
 }
 
-int quicktime_drep_dump(quicktime_drep_t *drep)
+void quicktime_drep_dump(quicktime_drep_t *drep)
 {
 	printf("    total repeated bytes\n");
 	printf("     numBytes "U64"\n", drep->numBytes);
 }
 
-int quicktime_read_drep(quicktime_t *file, quicktime_drep_t *drep)
+void quicktime_read_drep(quicktime_t *file, quicktime_drep_t *drep)
 {
 	drep->numBytes = quicktime_read_int64(file);
 }
 
-int quicktime_write_drep(quicktime_t *file, quicktime_drep_t *drep)
+void quicktime_write_drep(quicktime_t *file, quicktime_drep_t *drep)
 {
 	quicktime_atom_t atom;
 
