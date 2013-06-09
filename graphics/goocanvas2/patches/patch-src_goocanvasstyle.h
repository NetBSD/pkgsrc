$NetBSD: patch-src_goocanvasstyle.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasstyle.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasstyle.h
@@ -28,7 +28,7 @@ extern GQuark goo_canvas_style_hint_metr
 
 
 /**
- * GooCanvasStyleProperty
+ * GooCanvasStyleProperty:
  * @id: the unique property identifier.
  * @value: the value of the property.
  *
@@ -54,7 +54,7 @@ typedef struct _GooCanvasStyle       Goo
 typedef struct _GooCanvasStyleClass  GooCanvasStyleClass;
 
 /**
- * GooCanvasStyle
+ * GooCanvasStyle:
  * @parent: the parent style.
  * @properties: an array of #GooCanvasStyleProperty property settings.
  *
