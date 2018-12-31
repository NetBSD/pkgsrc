$NetBSD: patch-app_drawable.h,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/drawable.h.orig	2006-11-23 23:46:39.000000000 +0000
+++ app/drawable.h
@@ -32,7 +32,7 @@
 #define GIMP_DRAWABLE_CLASS(klass) GTK_CHECK_CLASS_CAST (klass, GIMP_TYPE_DRAWABLE, GimpDrawableClass)
 #define GIMP_IS_DRAWABLE(obj)      GTK_CHECK_TYPE (obj, GIMP_TYPE_DRAWABLE)
 
-guint gimp_drawable_get_type (void);
+GtkType gimp_drawable_get_type (void);
 
 
 /*  drawable access functions  */
