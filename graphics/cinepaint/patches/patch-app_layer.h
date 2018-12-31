$NetBSD: patch-app_layer.h,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/layer.h.orig	2004-02-09 20:25:12.000000000 +0000
+++ app/layer.h
@@ -51,8 +51,8 @@ typedef enum
 #define GIMP_IS_LAYER_MASK(obj)      GTK_CHECK_TYPE (obj, gimp_layer_mask_get_type())
 
 
-guint gimp_layer_get_type (void);
-guint gimp_layer_mask_get_type (void);
+GtkType gimp_layer_get_type (void);
+GtkType gimp_layer_mask_get_type (void);
 
 /*  Special undo types  */
 
