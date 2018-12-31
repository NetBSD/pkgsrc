$NetBSD: patch-lib_pixmap.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- lib/pixmap.c.orig	2004-02-10 01:40:39.000000000 +0000
+++ lib/pixmap.c
@@ -70,7 +70,7 @@ gimp_pixmap_init (GimpPixmap *pixmap)
 GtkType
 gimp_pixmap_get_type (void)
 {
-  static guint pixmap_type = 0;
+  static GtkType pixmap_type = 0;
 
   if (!pixmap_type)
     {
