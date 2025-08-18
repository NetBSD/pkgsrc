$NetBSD: patch-src_in_vorbis.c,v 1.1 2025/08/18 05:26:28 kim Exp $

Compare against title= and artist= to avoid accidentally matching
titlesort and artistsort.

--- src/in_vorbis.c.orig	2025-08-18 01:08:49.075203334 +0000
+++ src/in_vorbis.c
@@ -234,9 +234,9 @@ in_vorbis_set_metadata (ices_vorbis_in_t
   for (i = 0; i < comment->comments; i++) {
     key = comment->user_comments[i];
     ices_log_debug ("Vorbis comment found: %s", key);
-    if (! strncasecmp ("artist", key, 6))
+    if (! strncasecmp ("artist=", key, 7))
       artist = key+7;
-    else if (! strncasecmp ("title", key, 5))
+    else if (! strncasecmp ("title=", key, 6))
       title = key+6;
   }
 
