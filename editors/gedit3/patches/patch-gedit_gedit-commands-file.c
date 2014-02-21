$NetBSD: patch-gedit_gedit-commands-file.c,v 1.1 2014/02/21 20:23:48 joerg Exp $

--- gedit/gedit-commands-file.c.orig	2014-02-21 00:06:18.000000000 +0000
+++ gedit/gedit-commands-file.c
@@ -579,6 +579,9 @@ replace_read_only_file (GtkWindow *paren
 	return (ret == GTK_RESPONSE_YES);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
+
 static gboolean
 change_compression (GtkWindow *parent,
                     GFile     *file,
@@ -651,6 +654,7 @@ change_compression (GtkWindow *parent,
 
 	return (ret == GTK_RESPONSE_YES);
 }
+#pragma GCC diagnostic pop
 
 static GeditDocumentCompressionType
 get_compression_type_from_file (GFile *file)
