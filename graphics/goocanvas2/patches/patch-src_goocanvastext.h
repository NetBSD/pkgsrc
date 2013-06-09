$NetBSD: patch-src_goocanvastext.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvastext.h.orig	2010-09-06 10:28:24.000000000 +0000
+++ src/goocanvastext.h
@@ -39,7 +39,7 @@ typedef struct _GooCanvasText       GooC
 typedef struct _GooCanvasTextClass  GooCanvasTextClass;
 
 /**
- * GooCanvasText
+ * GooCanvasText:
  *
  * The #GooCanvasText-struct struct contains private data only.
  */
@@ -92,7 +92,7 @@ typedef struct _GooCanvasTextModel      
 typedef struct _GooCanvasTextModelClass  GooCanvasTextModelClass;
 
 /**
- * GooCanvasTextModel
+ * GooCanvasTextModel:
  *
  * The #GooCanvasTextModel-struct struct contains private data only.
  */
