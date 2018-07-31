$NetBSD: patch-src_jamendo_grl-jamendo.c,v 1.1 2018/07/31 14:27:35 jperkin Exp $

Apply upstream "format not a string literal" fixes.

--- src/jamendo/grl-jamendo.c.orig	2018-07-31 14:15:42.805159862 +0000
+++ src/jamendo/grl-jamendo.c
@@ -141,10 +141,12 @@ typedef struct {
   gboolean cancelled;
 } XmlParseEntries;
 
+/* Note: you'll also need to update
+ * grl_jamendo_source_browse() */
 struct Feeds {
   gchar *name;
   JamendoCategory cat;
-  gchar *url;
+  const gchar *url;
 } feeds[] = {
   { N_("Albums of the week"), JAMENDO_ALBUM_CAT,
     JAMENDO_GET_ALBUMS "&order=ratingweek_desc", },
@@ -1170,10 +1172,46 @@ grl_jamendo_source_browse (GrlSource *so
 
         feed_id = atoi (container_split[1]);
         jamendo_keys = get_jamendo_keys (feeds[feed_id].cat);
-        url = g_strdup_printf (feeds[feed_id].url,
-                               jamendo_keys,
-                               page_size,
-                               page_number);
+        switch (feed_id) {
+        case 0:
+          url = g_strdup_printf (JAMENDO_GET_ALBUMS "&order=ratingweek_desc",
+                                 jamendo_keys,
+                                 page_size,
+                                 page_number);
+          break;
+        case 1:
+          url = g_strdup_printf (JAMENDO_GET_TRACKS "&order=ratingweek_desc",
+                                 jamendo_keys,
+                                 page_size,
+                                 page_number);
+          break;
+        case 2:
+          url = g_strdup_printf (JAMENDO_GET_TRACKS "&order=releasedate_desc",
+                                 jamendo_keys,
+                                 page_size,
+                                 page_number);
+          break;
+        case 3:
+          url = g_strdup_printf (JAMENDO_GET_ARTISTS "&order=rating_desc",
+                                 jamendo_keys,
+                                 page_size,
+                                 page_number);
+          break;
+        case 4:
+          url = g_strdup_printf (JAMENDO_GET_ALBUMS "&order=rating_desc",
+                                 jamendo_keys,
+                                 page_size,
+                                 page_number);
+          break;
+        case 5:
+          url = g_strdup_printf (JAMENDO_GET_TRACKS "&order=rating_desc",
+                                 jamendo_keys,
+                                 page_size,
+                                 page_number);
+          break;
+        default:
+          g_assert_not_reached ();
+        }
         g_free (jamendo_keys);
       } else {
         send_feeds (bs);
@@ -1232,7 +1270,6 @@ grl_jamendo_source_query (GrlSource *sou
   gchar *term = NULL;
   gchar *url;
   gchar *jamendo_keys = NULL;
-  gchar *query = NULL;
   XmlParseEntries *xpe = NULL;
   guint page_size;
   guint page_number;
@@ -1250,33 +1287,40 @@ grl_jamendo_source_query (GrlSource *sou
     goto send_error;
   }
 
+  grl_paging_translate (skip,
+                        count,
+                        0,
+                        &page_size,
+                        &page_number,
+                        &page_offset);
+
   jamendo_keys = get_jamendo_keys (category);
   switch (category) {
   case JAMENDO_ARTIST_CAT:
-    query = JAMENDO_SEARCH_ARTIST;
+    url = g_strdup_printf (JAMENDO_SEARCH_ARTIST,
+                           jamendo_keys,
+                           page_size,
+                           page_number,
+                           term);
     break;
   case JAMENDO_ALBUM_CAT:
-    query = JAMENDO_SEARCH_ALBUM;
+    url = g_strdup_printf (JAMENDO_SEARCH_ALBUM,
+                           jamendo_keys,
+                           page_size,
+                           page_number,
+                           term);
     break;
   case JAMENDO_TRACK_CAT:
-    query = JAMENDO_SEARCH_TRACK;
+    url = g_strdup_printf (JAMENDO_SEARCH_TRACK,
+                           jamendo_keys,
+                           page_size,
+                           page_number,
+                           term);
     break;
   default:
     g_return_if_reached ();
   }
 
-  grl_paging_translate (skip,
-                        count,
-                        0,
-                        &page_size,
-                        &page_number,
-                        &page_offset);
-
-  url = g_strdup_printf (query,
-                         jamendo_keys,
-                         page_size,
-                         page_number,
-                         term);
   g_free (term);
   g_free (jamendo_keys);
 
