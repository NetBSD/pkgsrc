$NetBSD: patch-lib_mp4_hnti.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/hnti.c.orig	2012-12-20 16:53:34.000000000 +0000
+++ lib/mp4/hnti.c
@@ -53,7 +53,9 @@ int quicktime_read_hnti(quicktime_t *fil
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hnti(quicktime_t *file, quicktime_hnti_t *hnti)
+void quicktime_write_rtp(quicktime_t *file, quicktime_rtp_t *rtp);
+
+void quicktime_write_hnti(quicktime_t *file, quicktime_hnti_t *hnti)
 {
 	quicktime_atom_t atom;
 
