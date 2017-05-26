$NetBSD: patch-ui_gtk_gtkui.c,v 1.1 2017/05/26 19:35:48 adam Exp $

Fix for a case when GTK has been compiled with Quartz support.

--- ui/gtk/gtkui.c.orig	2010-12-20 20:17:04.000000000 +0000
+++ ui/gtk/gtkui.c
@@ -28,8 +28,10 @@
 #include <stdio.h>
 
 #include <gdk/gdkkeysyms.h>
-#include <gdk/gdkx.h>
 #include <gtk/gtk.h>
+#ifndef GDK_WINDOWING_QUARTZ
+#include <gdk/gdkx.h>
+#endif
 
 #include <glib.h>
 
