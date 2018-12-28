$NetBSD: patch-src_af_gr_gtk_gr__UnixImage.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13834, SVN revision 35393: Crash fixes.

--- src/af/gr/gtk/gr_UnixImage.cpp.orig	2015-10-16 02:42:45.000000000 +0000
+++ src/af/gr/gtk/gr_UnixImage.cpp
@@ -244,12 +244,13 @@ bool GR_UnixImage::saveToPNG(const char 
         UT_return_val_if_fail(m_image,false);
 
 	GError * error = NULL;
-	gboolean res = gdk_pixbuf_save (m_image, szFile, "png", &error,NULL);
-	if(res != FALSE)
-	{
+	gboolean res = gdk_pixbuf_save (m_image, szFile, "png", &error, NULL);
+	if (res != FALSE) {
+		if (error) {
+			g_error_free (error);
+		}
 		return true;
 	}
-	delete error;
 	return false;
 
 }
