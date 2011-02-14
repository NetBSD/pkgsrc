$NetBSD: patch-src_im__png.h,v 1.2 2011/02/14 19:16:14 wiz Exp $

Fix build with png-1.5.
http://developer.berlios.de/patch/?func=detailpatch&patch_id=3131&group_id=735

--- src/im_png.h.orig	2004-02-14 15:16:33.000000000 +0000
+++ src/im_png.h
@@ -31,7 +31,7 @@
 
 typedef	gboolean	(*PngLoadFunc)		(guchar *buffer, gint width, gint left, gint scanline, gint components, gint pass, gint mode);
 
-gboolean	png_get_header		(gchar *filename, png_info *info);
+gboolean	png_get_header		(gchar *filename, gint *, gint *, png_bytep);
 gboolean	png_load		(gchar *filename, PngLoadFunc func);
 
 #endif /* HAVE_LIBPNG */
