$NetBSD: patch-lib_mp4_hinthnti.c,v 1.1 2012/12/20 21:44:51 joerg Exp $

--- lib/mp4/hinthnti.c.orig	2012-12-20 16:54:04.000000000 +0000
+++ lib/mp4/hinthnti.c
@@ -53,7 +53,9 @@ int quicktime_read_hint_hnti(quicktime_t
 	} while (quicktime_position(file) < parent_atom->end);
 }
 
-int quicktime_write_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti)
+void quicktime_write_sdp(quicktime_t *file, quicktime_sdp_t *sdp);
+
+void quicktime_write_hint_hnti(quicktime_t *file, quicktime_hint_hnti_t *hnti)
 {
 	quicktime_atom_t atom;
 
