$NetBSD: patch-src_goocanvastable.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvastable.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvastable.h
@@ -60,7 +60,7 @@ typedef struct _GooCanvasTable       Goo
 typedef struct _GooCanvasTableClass  GooCanvasTableClass;
 
 /**
- * GooCanvasTable
+ * GooCanvasTable:
  *
  * The #GooCanvasTable-struct struct contains private data only.
  */
@@ -104,7 +104,7 @@ typedef struct _GooCanvasTableModel     
 typedef struct _GooCanvasTableModelClass  GooCanvasTableModelClass;
 
 /**
- * GooCanvasTableModel
+ * GooCanvasTableModel:
  *
  * The #GooCanvasTableModel-struct struct contains private data only.
  */
