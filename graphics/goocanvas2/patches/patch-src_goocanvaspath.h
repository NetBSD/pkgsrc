$NetBSD: patch-src_goocanvaspath.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvaspath.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvaspath.h
@@ -34,7 +34,7 @@ typedef struct _GooCanvasPath       GooC
 typedef struct _GooCanvasPathClass  GooCanvasPathClass;
 
 /**
- * GooCanvasPath
+ * GooCanvasPath:
  *
  * The #GooCanvasPath-struct struct contains private data only.
  */
@@ -79,7 +79,7 @@ typedef struct _GooCanvasPathModel      
 typedef struct _GooCanvasPathModelClass  GooCanvasPathModelClass;
 
 /**
- * GooCanvasPathModel
+ * GooCanvasPathModel:
  *
  * The #GooCanvasPathModel-struct struct contains private data only.
  */
