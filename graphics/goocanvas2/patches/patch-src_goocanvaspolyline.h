$NetBSD: patch-src_goocanvaspolyline.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvaspolyline.h.orig	2011-10-07 20:48:35.000000000 +0000
+++ src/goocanvaspolyline.h
@@ -14,7 +14,7 @@ G_BEGIN_DECLS
 
 
 /**
- * GooCanvasPoints
+ * GooCanvasPoints:
  * @coords: the coordinates of the points, in pairs.
  * @num_points: the number of points.
  * @ref_count: the reference count of the struct.
@@ -81,7 +81,7 @@ typedef struct _GooCanvasPolyline       
 typedef struct _GooCanvasPolylineClass  GooCanvasPolylineClass;
 
 /**
- * GooCanvasPolyline
+ * GooCanvasPolyline:
  *
  * The #GooCanvasPolyline-struct struct contains private data only.
  */
@@ -134,7 +134,7 @@ typedef struct _GooCanvasPolylineModel  
 typedef struct _GooCanvasPolylineModelClass  GooCanvasPolylineModelClass;
 
 /**
- * GooCanvasPolylineModel
+ * GooCanvasPolylineModel:
  *
  * The #GooCanvasPolylineModel-struct struct contains private data only.
  */
