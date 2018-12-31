$NetBSD: patch-app_depth_layer.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/depth/layer.c.orig	2007-11-09 15:26:15.000000000 +0000
+++ app/depth/layer.c
@@ -65,10 +65,10 @@ static gint layer_mask_signals[LAST_SIGN
 static CanvasDrawableClass *layer_parent_class = NULL;
 static GimpChannelClass *layer_mask_parent_class = NULL;
 
-guint
+GtkType 
 gimp_layer_get_type ()
 {
-  static guint layer_type = 0;
+  static GtkType layer_type = 0;
 
   if (!layer_type)
     {
@@ -118,10 +118,10 @@ gimp_layer_init (GimpLayer *layer)
 {
 }
 
-guint
+GtkType
 gimp_layer_mask_get_type ()
 {
-  static guint layer_mask_type = 0;
+  static GtkType layer_mask_type = 0;
 
   if (!layer_mask_type)
     {
