$NetBSD: patch-src_goocanvasitem.c,v 1.1 2013/06/09 13:25:14 obache Exp $

* Use GObject.Object instead of GLib.Object in introspection annotations
  https://git.gnome.org/browse/goocanvas/commit/?id=2088843efb50f05b8965340eddbf7c0103c6eef1
* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasitem.c.orig	2011-10-09 18:03:37.000000000 +0000
+++ src/goocanvasitem.c
@@ -117,7 +117,7 @@ goo_canvas_item_base_init (gpointer g_if
       /* Mouse events. */
 
       /**
-       * GooCanvasItem::enter-notify-event
+       * GooCanvasItem::enter-notify-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data. The x & y fields contain the mouse position
@@ -142,7 +142,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::leave-notify-event
+       * GooCanvasItem::leave-notify-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data. The x & y fields contain the mouse position
@@ -167,7 +167,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::motion-notify-event
+       * GooCanvasItem::motion-notify-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data. The x & y fields contain the mouse position
@@ -192,7 +192,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::button-press-event
+       * GooCanvasItem::button-press-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data. The x & y fields contain the mouse position
@@ -217,7 +217,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::button-release-event
+       * GooCanvasItem::button-release-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data. The x & y fields contain the mouse position
@@ -245,7 +245,7 @@ goo_canvas_item_base_init (gpointer g_if
       /* Keyboard events. */
 
       /**
-       * GooCanvasItem::focus-in-event
+       * GooCanvasItem::focus-in-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data.
@@ -268,7 +268,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::focus-out-event
+       * GooCanvasItem::focus-out-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data.
@@ -291,7 +291,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::key-press-event
+       * GooCanvasItem::key-press-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data.
@@ -315,7 +315,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::key-release-event
+       * GooCanvasItem::key-release-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data.
@@ -371,7 +371,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      GTK_TYPE_TOOLTIP);
 
       /**
-       * GooCanvasItem::grab-broken-event
+       * GooCanvasItem::grab-broken-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data.
@@ -395,9 +395,9 @@ goo_canvas_item_base_init (gpointer g_if
 		      GDK_TYPE_EVENT | G_SIGNAL_TYPE_STATIC_SCOPE);
 
       /**
-       * GooCanvasItem::child-notify
+       * GooCanvasItem::child-notify:
        * @item: the item that received the signal.
-       * @pspec: (type GLib.ParamSpec): the #GParamSpec of the changed child property.
+       * @pspec: (type GObject.ParamSpec): the #GParamSpec of the changed child property.
        *
        * Emitted for each child property that has changed.
        * The signal's detail holds the property name. 
@@ -413,7 +413,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      G_TYPE_PARAM);
 
       /**
-       * GooCanvasItem::animation-finished
+       * GooCanvasItem::animation-finished:
        * @item: the item that received the signal.
        * @stopped: if the animation was explicitly stopped.
        *
@@ -430,7 +430,7 @@ goo_canvas_item_base_init (gpointer g_if
 		      G_TYPE_BOOLEAN);
 
       /**
-       * GooCanvasItem::scroll-event
+       * GooCanvasItem::scroll-event:
        * @item: the item that received the signal.
        * @target_item: the target of the event.
        * @event: the event data. The x & y fields contain the mouse position
