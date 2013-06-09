$NetBSD: patch-src_goocanvasitemmodel.c,v 1.1 2013/06/09 13:25:14 obache Exp $

* Use GObject.Object instead of GLib.Object in introspection annotations
  https://git.gnome.org/browse/goocanvas/commit/?id=2088843efb50f05b8965340eddbf7c0103c6eef1
* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasitemmodel.c.orig	2011-10-01 15:07:18.000000000 +0000
+++ src/goocanvasitemmodel.c
@@ -115,7 +115,7 @@ goo_canvas_item_model_base_init (gpointe
       _goo_canvas_item_model_child_property_notify_context = &cpn_context;
 
       /**
-       * GooCanvasItemModel::child-added
+       * GooCanvasItemModel::child-added:
        * @model: the item model that received the signal.
        * @child_num: the index of the new child.
        *
@@ -132,7 +132,7 @@ goo_canvas_item_model_base_init (gpointe
 		      G_TYPE_INT);
 
       /**
-       * GooCanvasItemModel::child-moved
+       * GooCanvasItemModel::child-moved:
        * @model: the item model that received the signal.
        * @old_child_num: the old index of the child.
        * @new_child_num: the new index of the child.
@@ -150,7 +150,7 @@ goo_canvas_item_model_base_init (gpointe
 		      G_TYPE_INT, G_TYPE_INT);
 
       /**
-       * GooCanvasItemModel::child-removed
+       * GooCanvasItemModel::child-removed:
        * @model: the item model that received the signal.
        * @child_num: the index of the child that was removed.
        *
@@ -167,7 +167,7 @@ goo_canvas_item_model_base_init (gpointe
 		      G_TYPE_INT);
 
       /**
-       * GooCanvasItemModel::changed
+       * GooCanvasItemModel::changed:
        * @model: the item model that received the signal.
        * @recompute_bounds: if the bounds of the item need to be recomputed.
        *
@@ -184,9 +184,9 @@ goo_canvas_item_model_base_init (gpointe
 		      G_TYPE_BOOLEAN);
 
       /**
-       * GooCanvasItemModel::child-notify
+       * GooCanvasItemModel::child-notify:
        * @item: the item model that received the signal.
-       * @pspec: (type GLib.ParamSpec): the #GParamSpec of the changed child property.
+       * @pspec: (type GObject.ParamSpec): the #GParamSpec of the changed child property.
        *
        * Emitted for each child property that has changed.
        * The signal's detail holds the property name. 
@@ -202,7 +202,7 @@ goo_canvas_item_model_base_init (gpointe
 		      G_TYPE_PARAM);
 
       /**
-       * GooCanvasItemModel::animation-finished
+       * GooCanvasItemModel::animation-finished:
        * @item: the item model that received the signal.
        * @stopped: if the animation was explicitly stopped.
        *
@@ -1126,7 +1126,7 @@ goo_canvas_item_model_class_install_chil
  *
  * It finds a child property of a canvas item class by name.
  *
- * Returns: (type GLib.ParamSpec) (transfer none): The #GParamSpec of the child
+ * Returns: (type GObject.ParamSpec) (transfer none): The #GParamSpec of the child
  *  property or %NULL if @class has no child property with that name.
  */
 GParamSpec*
@@ -1152,7 +1152,7 @@ goo_canvas_item_model_class_find_child_p
  *
  * It returns all child properties of a canvas item class.
  *
- * Returns: (array length=n_properties) (element-type GLib.ParamSpec) (transfer container):
+ * Returns: (array length=n_properties) (element-type Object.ParamSpec) (transfer container):
  *  a newly allocated array of #GParamSpec*. The array must be freed with g_free(). 
  */
 GParamSpec**
