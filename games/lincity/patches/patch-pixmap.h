$NetBSD: patch-pixmap.h,v 1.1 2012/07/03 18:41:20 joerg Exp $

--- pixmap.h.orig	2012-07-03 15:36:29.000000000 +0000
+++ pixmap.h
@@ -19,7 +19,7 @@ extern int pixmap_width;
 void initialize_pixmap (void);
 void resize_pixmap (int new_width, int new_height);
 int pixmap_getpixel (int x, int y);
-inline int pixmap_index (int x, int y);
+int pixmap_index (int x, int y);
 int pixmap_getpixel (int x, int y);
 void pixmap_setpixel (int x, int y, int col);
 void pixmap_hline (int x1, int y1, int x2, int col);
