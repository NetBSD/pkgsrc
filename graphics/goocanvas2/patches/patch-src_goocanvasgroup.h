$NetBSD: patch-src_goocanvasgroup.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasgroup.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasgroup.h
@@ -29,7 +29,7 @@ typedef struct _GooCanvasGroupModel     
 typedef struct _GooCanvasGroupModelClass  GooCanvasGroupModelClass;
 
 /**
- * GooCanvasGroup
+ * GooCanvasGroup:
  *
  * The #GooCanvasGroup-struct struct contains private data only.
  */
@@ -72,7 +72,7 @@ GooCanvasItem* goo_canvas_group_new     
 
 
 /**
- * GooCanvasGroupModel
+ * GooCanvasGroupModel:
  *
  * The #GooCanvasGroupModel-struct struct contains private data only.
  */
