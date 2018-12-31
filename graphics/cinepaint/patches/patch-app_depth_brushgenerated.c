$NetBSD: patch-app_depth_brushgenerated.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/depth/brushgenerated.c.orig	2007-03-07 20:02:36.000000000 +0000
+++ app/depth/brushgenerated.c
@@ -106,9 +106,9 @@ gimp_brush_generated_init(GimpBrushGener
   brush->freeze        = 0;
 }
 
-guint gimp_brush_generated_get_type(void)
+GtkType gimp_brush_generated_get_type(void)
 {
-  static GtkType type;
+  static GtkType type = 0;
   if(!type){
     GtkTypeInfo info={
       "GimpBrushGenerated",
