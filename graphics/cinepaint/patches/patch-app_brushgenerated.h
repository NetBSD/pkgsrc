$NetBSD: patch-app_brushgenerated.h,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/brushgenerated.h.orig	2004-02-09 20:25:11.000000000 +0000
+++ app/brushgenerated.h
@@ -51,7 +51,7 @@ struct GimpBrushGeneratedClass
 #define GIMP_BRUSH_GENERATED(obj)  (GIMP_CHECK_CAST ((obj), GIMP_TYPE_BRUSH_GENERATED, GimpBrushGenerated))
 #define GIMP_IS_BRUSH_GENERATED(obj) (GIMP_CHECK_TYPE ((obj), GIMP_TYPE_BRUSH_GENERATED))
 
-guint gimp_brush_generated_get_type (void);
+GtkType gimp_brush_generated_get_type (void);
 
 /* normal stuff */
 
