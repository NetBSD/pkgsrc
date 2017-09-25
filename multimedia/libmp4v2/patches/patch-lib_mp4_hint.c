$NetBSD: patch-lib_mp4_hint.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/hint.c.orig	2017-09-25 14:53:35.749860457 +0000
+++ lib/mp4/hint.c
@@ -22,25 +22,25 @@
 #include "quicktime.h"
 
 
-int quicktime_hint_init(quicktime_hint_t *hint)
+void quicktime_hint_init(quicktime_hint_t *hint)
 {
 	hint->numTracks = 0;
 	hint->trackIds[0] = -1;
 	hint->traks[0] = NULL;
 }
 
-int quicktime_hint_set(quicktime_hint_t *hint, quicktime_trak_t *refTrak)
+void quicktime_hint_set(quicktime_hint_t *hint, quicktime_trak_t *refTrak)
 {
 	hint->traks[hint->numTracks] = refTrak;
 	hint->trackIds[hint->numTracks] = refTrak->tkhd.track_id;
 	hint->numTracks++;
 }
 
-int quicktime_hint_delete(quicktime_hint_t *hint)
+void quicktime_hint_delete(quicktime_hint_t *hint)
 {
 }
 
-int quicktime_read_hint(quicktime_t *file, quicktime_hint_t *hint, quicktime_atom_t *parent_atom)
+void quicktime_read_hint(quicktime_t *file, quicktime_hint_t *hint, quicktime_atom_t *parent_atom)
 {
 	quicktime_trak_t* refTrak = NULL;
 	int i;
@@ -52,7 +52,7 @@ int quicktime_read_hint(quicktime_t *fil
 	}
 }
 
-int quicktime_write_hint(quicktime_t *file, quicktime_hint_t *hint)
+void quicktime_write_hint(quicktime_t *file, quicktime_hint_t *hint)
 {
 	quicktime_atom_t atom;
 	int i;
@@ -66,13 +66,13 @@ int quicktime_write_hint(quicktime_t *fi
 	quicktime_atom_write_footer(file, &atom);
 }
 
-int quicktime_hint_dump(quicktime_hint_t *hint)
+void quicktime_hint_dump(quicktime_hint_t *hint)
 {
 	int i;
 
 	printf("   hint\n");
 	for (i = 0; i < hint->numTracks; i++) {
-		printf("    track %d\n", hint->trackIds[i]);
+		printf("    track %ld\n", hint->trackIds[i]);
 	}
 }
 
