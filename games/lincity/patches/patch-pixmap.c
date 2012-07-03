$NetBSD: patch-pixmap.c,v 1.1 2012/07/03 18:41:20 joerg Exp $

--- pixmap.c.orig	2012-07-03 15:36:45.000000000 +0000
+++ pixmap.c
@@ -390,7 +390,7 @@ resize_pixmap (int new_width, int new_he
 		  likes it in the file.  Still need to fix this in autoconf,
                   but for now this will do. */
 #if !defined (WIN32)
-inline int 
+int 
 pixmap_index (int x, int y)
 {
     return y*pixmap_width + x;
