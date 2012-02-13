$NetBSD: patch-src_swfmoz_player.c,v 1.1 2012/02/13 11:36:43 martin Exp $

# Upstream bugreport:
#  http://bugs.freedesktop.org/show_bug.cgi?id=45794

--- src/swfmoz_player.c.orig	2008-09-24 11:18:44.000000000 +0200
+++ src/swfmoz_player.c	2012-02-08 18:17:29.000000000 +0100
@@ -610,7 +610,7 @@
 swfmoz_player_loaders_update (GtkListStore *store, GtkTreeIter *iter, SwfdecLoader *loader)
 {
   goffset loaded, size;
-  gboolean error;
+  gpointer error = NULL;
   const SwfdecURL *url;
   SwfdecPlayer *player;
   const char *url_string;
@@ -623,7 +623,7 @@
   /* FIXME: swfdec needs a function for this */
   g_object_get (G_OBJECT (loader), "error", &error, NULL);
 
-  if (error == TRUE) {
+  if (error != NULL) {
     status = g_strdup("error");
   } else {
     str_loaded = g_format_size_for_display(loaded);
