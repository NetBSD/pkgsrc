$NetBSD: patch-src_goocanvasrect.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasrect.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasrect.h
@@ -33,7 +33,7 @@ typedef struct _GooCanvasRect       GooC
 typedef struct _GooCanvasRectClass  GooCanvasRectClass;
 
 /**
- * GooCanvasRect
+ * GooCanvasRect:
  *
  * The #GooCanvasRect-struct struct contains private data only.
  */
@@ -81,7 +81,7 @@ typedef struct _GooCanvasRectModel      
 typedef struct _GooCanvasRectModelClass  GooCanvasRectModelClass;
 
 /**
- * GooCanvasRectModel
+ * GooCanvasRectModel:
  *
  * The #GooCanvasRectModel-struct struct contains private data only.
  */
