$NetBSD: patch-src_image__browser.c,v 1.1 2013/03/02 18:13:49 joerg Exp $

--- src/image_browser.c.orig	2013-03-01 14:29:19.000000000 +0000
+++ src/image_browser.c
@@ -654,7 +654,7 @@ static void on_mni_copy_pixbuf (GtkMenuI
 {
   GtkClipboard *c = gtk_clipboard_get (GDK_SELECTION_CLIPBOARD);
   if (! c)
-     return NULL;
+     return;
 
   t_image_viewer *instance = user_data;
   gtk_clipboard_set_image (c, gtk_image_get_pixbuf (instance->image));
@@ -1005,7 +1005,7 @@ GtkWidget* create_image_browser (t_image
 void image_browser_update (t_image_plane *instance)
 {
   if (! instance)
-     return NULL;
+     return;
 
   gchar *filename;
   gchar *utf;
