$NetBSD: patch-src_goocanvasellipse.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasellipse.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasellipse.h
@@ -33,7 +33,7 @@ typedef struct _GooCanvasEllipse       G
 typedef struct _GooCanvasEllipseClass  GooCanvasEllipseClass;
 
 /**
- * GooCanvasEllipse
+ * GooCanvasEllipse:
  *
  * The #GooCanvasEllipse-struct struct contains private data only.
  */
@@ -81,7 +81,7 @@ typedef struct _GooCanvasEllipseModel   
 typedef struct _GooCanvasEllipseModelClass  GooCanvasEllipseModelClass;
 
 /**
- * GooCanvasEllipseModel
+ * GooCanvasEllipseModel:
  *
  * The #GooCanvasEllipseModel-struct struct contains private data only.
  */
