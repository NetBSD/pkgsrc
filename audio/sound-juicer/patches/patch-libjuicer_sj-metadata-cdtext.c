$NetBSD: patch-libjuicer_sj-metadata-cdtext.c,v 1.1 2014/10/17 16:45:12 joerg Exp $

--- libjuicer/sj-metadata-cdtext.c.orig	2014-10-17 14:06:03.000000000 +0000
+++ libjuicer/sj-metadata-cdtext.c
@@ -82,11 +82,11 @@ cdtext_list_albums (SjMetadata *metadata
   album = g_new0 (AlbumDetails, 1);
 
   /* TODO: why can't I do this first? */
-  cdtext = cdio_get_cdtext(cdio, 0);
+  cdtext = cdio_get_cdtext(cdio);
   if (cdtext) {
-    album->title = g_strdup (cdtext_get (CDTEXT_TITLE, cdtext));
-    album->artist = g_strdup (cdtext_get (CDTEXT_PERFORMER, cdtext));
-    album->genre = g_strdup (cdtext_get (CDTEXT_GENRE, cdtext));
+    album->title = g_strdup (cdtext_get (cdtext, CDTEXT_FIELD_TITLE, 0));
+    album->artist = g_strdup (cdtext_get (cdtext, CDTEXT_FIELD_PERFORMER, 0));
+    album->genre = g_strdup (cdtext_get (cdtext, CDTEXT_FIELD_GENRE, 0));
 
     album->metadata_source = SOURCE_CDTEXT;
   } else {
@@ -105,10 +105,10 @@ cdtext_list_albums (SjMetadata *metadata
     track = g_new0 (TrackDetails, 1);
     track->album = album;
     track->number = cdtrack;
-    cdtext = cdio_get_cdtext(cdio, cdtrack);
+    cdtext = cdio_get_cdtext(cdio);
     if (cdtext) {
-      track->title = g_strdup (cdtext_get (CDTEXT_TITLE, cdtext));
-      track->artist = g_strdup (cdtext_get (CDTEXT_PERFORMER, cdtext));
+      track->title = g_strdup (cdtext_get (cdtext, CDTEXT_FIELD_TITLE, cdtrack));
+      track->artist = g_strdup (cdtext_get (cdtext, CDTEXT_FIELD_PERFORMER, cdtrack));
     } else {
       track->title = g_strdup_printf (_("Track %d"), cdtrack);
       track->artist = g_strdup (_("Unknown Artist"));
