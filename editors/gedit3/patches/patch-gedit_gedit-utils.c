$NetBSD: patch-gedit_gedit-utils.c,v 1.1 2014/02/21 20:23:48 joerg Exp $

--- gedit/gedit-utils.c.orig	2014-02-21 00:07:38.000000000 +0000
+++ gedit/gedit-utils.c
@@ -911,7 +911,7 @@ gedit_utils_is_valid_location (GFile *lo
 	return is_valid;
 }
 
-static GtkWidget *
+static G_GNUC_PRINTF(1, 2) GtkWidget *
 handle_builder_error (const gchar *message, ...)
 {
 	GtkWidget *label;
