$NetBSD: patch-app_drawable.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/drawable.c.orig	2007-11-09 15:24:26.000000000 +0000
+++ app/drawable.c
@@ -56,10 +56,10 @@ static gint drawable_signals[LAST_SIGNAL
 
 static CanvasDrawableClass *parent_class = NULL;
 
-guint
+GtkType
 gimp_drawable_get_type ()
 {
-  static guint drawable_type = 0;
+  static GtkType drawable_type = 0;
 
   if (!drawable_type)
     {
