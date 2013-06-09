$NetBSD: patch-src_goocanvasgrid.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasgrid.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasgrid.h
@@ -59,7 +59,7 @@ typedef struct _GooCanvasGrid       GooC
 typedef struct _GooCanvasGridClass  GooCanvasGridClass;
 
 /**
- * GooCanvasGrid
+ * GooCanvasGrid:
  *
  * The #GooCanvasGrid-struct struct contains private data only.
  */
@@ -110,7 +110,7 @@ typedef struct _GooCanvasGridModel      
 typedef struct _GooCanvasGridModelClass  GooCanvasGridModelClass;
 
 /**
- * GooCanvasGridModel
+ * GooCanvasGridModel:
  *
  * The #GooCanvasGridModel-struct struct contains private data only.
  */
