$NetBSD: patch-lib_mp4_ctts.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/ctts.c.orig	2012-12-20 16:51:30.000000000 +0000
+++ lib/mp4/ctts.c
@@ -88,7 +88,7 @@ int quicktime_read_ctts(quicktime_t *fil
 	}
 }
 
-int quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
+void quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
 {
 	int i;
 	quicktime_atom_t atom;
