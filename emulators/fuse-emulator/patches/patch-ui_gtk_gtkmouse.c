$NetBSD: patch-ui_gtk_gtkmouse.c,v 1.2 2018/12/12 16:45:52 adam Exp $

Fix for a case when GTK has been compiled with Quartz support.

--- ui/gtk/gtkmouse.c.orig	2018-12-09 12:06:11.000000000 +0000
+++ ui/gtk/gtkmouse.c
@@ -35,8 +35,10 @@
 #endif
 
 /* For XWarpPointer *only* - see below */
+#ifndef GDK_WINDOWING_QUARTZ
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
+#endif
 
 static GdkCursor *nullpointer = NULL;
 
@@ -64,8 +66,10 @@ gtkmouse_reset_pointer( void )
 #endif                /* #ifdef GDK_WINDOWING_WAYLAND */
 
   window = gtk_widget_get_window( mouse_widget );
+#ifndef GDK_WINDOWING_QUARTZ
   XWarpPointer( GDK_WINDOW_XDISPLAY( window ), None, 
                 GDK_WINDOW_XID( window ), 0, 0, 0, 0, 128, 128 );
+#endif
 }
 
 static gboolean
