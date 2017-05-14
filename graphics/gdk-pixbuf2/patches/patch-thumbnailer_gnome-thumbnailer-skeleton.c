$NetBSD: patch-thumbnailer_gnome-thumbnailer-skeleton.c,v 1.1 2017/05/14 12:55:16 spz Exp $

from https://bug778204.bugzilla-attachments.gnome.org/attachment.cgi?id=349903
for CVE-2017-6311

--- thumbnailer/gnome-thumbnailer-skeleton.c.orig	2017-02-13 15:58:32.000000000 +0000
+++ thumbnailer/gnome-thumbnailer-skeleton.c
@@ -315,11 +315,15 @@ int main (int argc, char **argv)
 #endif
 	g_free (input_filename);
 
-	if (!pixbuf) {
+	if (!pixbuf && error) {
 		g_warning ("Could not thumbnail '%s': %s", filenames[0], error->message);
 		g_error_free (error);
 		g_strfreev (filenames);
 		return 1;
+	} else if (!pixbuf) {
+		g_warning ("Could not thumbnail '%s'", filenames[0]);
+		g_strfreev (filenames);
+		return 1;
 	}
 
 	if (gdk_pixbuf_save (pixbuf, output, "png", &error, NULL) == FALSE) {
