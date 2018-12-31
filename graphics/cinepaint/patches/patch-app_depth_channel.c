$NetBSD: patch-app_depth_channel.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/depth/channel.c.orig	2008-06-09 16:25:24.000000000 +0000
+++ app/depth/channel.c
@@ -51,10 +51,9 @@ static void gimp_channel_destroy    (Gtk
 static GimpDrawableClass *parent_class = NULL;
 
 
-guint
-gimp_channel_get_type ()
+GtkType gimp_channel_get_type ()
 {
-  static guint channel_type = 0;
+  static GtkType channel_type = 0;
 
   if (!channel_type)
     {
