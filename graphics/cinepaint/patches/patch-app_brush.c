$NetBSD: patch-app_brush.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/brush.c.orig	2007-11-09 15:24:26.000000000 +0000
+++ app/brush.c
@@ -102,7 +102,7 @@ gimp_brush_init(GimpBrush *brush)
 
 GtkType gimp_brush_get_type(void)
 {
-  static GtkType type;
+  static GtkType type = 0;
   if(!type){
 #if GTK_MAJOR_VERSION > 1
       static const GTypeInfo info =
