$NetBSD: patch-lib_mp4_stbl.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/stbl.c.orig	2012-12-20 16:52:08.000000000 +0000
+++ lib/mp4/stbl.c
@@ -130,6 +130,8 @@ int quicktime_read_stbl(quicktime_t *fil
 	return 0;
 }
 
+void quicktime_write_ctts(quicktime_t *file, quicktime_ctts_t *ctts);
+
 int quicktime_write_stbl(quicktime_t *file, quicktime_minf_t *minf, quicktime_stbl_t *stbl)
 {
 	quicktime_atom_t atom;
