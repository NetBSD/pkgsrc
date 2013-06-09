$NetBSD: patch-src_goocanvaswidget.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvaswidget.h.orig	2010-09-06 10:28:24.000000000 +0000
+++ src/goocanvaswidget.h
@@ -25,7 +25,7 @@ typedef struct _GooCanvasWidget       Go
 typedef struct _GooCanvasWidgetClass  GooCanvasWidgetClass;
 
 /**
- * GooCanvasWidget
+ * GooCanvasWidget:
  *
  * The #GooCanvasWidget-struct struct contains private data only.
  */
