$NetBSD: patch-lib_mp4_ctts.c,v 1.1 2017/05/06 18:12:00 maya Exp $

Fix return type. we're not returning anything.

--- lib/mp4/ctts.c.orig	2001-08-01 00:34:00.000000000 +0000
+++ lib/mp4/ctts.c
@@ -88,7 +88,7 @@ int quicktime_read_ctts(quicktime_t *fil
 	}
 }
 
-int quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
+void quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts)
 {
 	int i;
 	quicktime_atom_t atom;
