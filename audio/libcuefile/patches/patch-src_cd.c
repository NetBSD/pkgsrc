$NetBSD: patch-src_cd.c,v 1.1 2026/07/17 13:14:41 adam Exp $

error: chained comparison 'X <= Y < Z' does not behave the same as a mathematical expression

--- src/cd.c.orig	2026-07-17 12:57:07.698217027 +0000
+++ src/cd.c
@@ -173,7 +173,7 @@ int cd_get_ntrack (Cd *cd)
 
 Track *cd_get_track (Cd *cd, int i)
 {
-	if (0 < i <= cd->ntrack)
+	if (0 < i && i <= cd->ntrack)
 		return cd->track[i - 1];
 
 	return NULL;
@@ -306,7 +306,7 @@ int track_get_nindex (Track *track)
 
 long track_get_index (Track *track, int i)
 {
-	if (0 <= i < track->nindex)
+	if (0 <= i && i < track->nindex)
 		return track->index[i];
 
 	return -1;
