$NetBSD: patch-src_goocanvasimage.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasimage.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasimage.h
@@ -35,7 +35,7 @@ typedef struct _GooCanvasImage       Goo
 typedef struct _GooCanvasImageClass  GooCanvasImageClass;
 
 /**
- * GooCanvasImage
+ * GooCanvasImage:
  *
  * The #GooCanvasImage-struct struct contains private data only.
  */
@@ -82,7 +82,7 @@ typedef struct _GooCanvasImageModel     
 typedef struct _GooCanvasImageModelClass  GooCanvasImageModelClass;
 
 /**
- * GooCanvasImageModel
+ * GooCanvasImageModel:
  *
  * The #GooCanvasImageModel-struct struct contains private data only.
  */
