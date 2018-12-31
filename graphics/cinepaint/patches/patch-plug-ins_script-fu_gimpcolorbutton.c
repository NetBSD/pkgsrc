$NetBSD: patch-plug-ins_script-fu_gimpcolorbutton.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- plug-ins/script-fu/gimpcolorbutton.c.orig	2007-01-01 21:49:24.000000000 +0000
+++ plug-ins/script-fu/gimpcolorbutton.c
@@ -223,7 +223,7 @@ gimp_color_button_init (GimpColorButton 
 GtkType
 gimp_color_button_get_type (void)
 {
-  static guint type = 0;
+  static GtkType type = 0;
 
   if (!type)
     {
