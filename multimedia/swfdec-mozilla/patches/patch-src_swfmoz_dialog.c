$NetBSD: patch-src_swfmoz_dialog.c,v 1.1 2012/02/13 11:36:43 martin Exp $

# Upstream bugreport:
#  http://bugs.freedesktop.org/show_bug.cgi?id=45794

--- src/swfmoz_dialog.c.orig	2008-06-17 11:37:20.000000000 +0200
+++ src/swfmoz_dialog.c	2012-02-13 11:51:18.000000000 +0100
@@ -120,7 +120,7 @@
   SwfmozLoader *loader;
   GtkWidget *chooser;
   char *s, *filename;
-  gboolean error;
+  gpointer error = NULL;
 
   selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (dialog->media));
   /* FIXME: assert this doesn't happen? */
