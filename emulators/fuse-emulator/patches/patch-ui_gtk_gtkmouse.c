$NetBSD: patch-ui_gtk_gtkmouse.c,v 1.1 2017/05/26 19:35:48 adam Exp $

Fix for a case when GTK has been compiled with Quartz support.

--- ui/gtk/gtkmouse.c.orig	2017-05-26 17:42:26.000000000 +0000
+++ ui/gtk/gtkmouse.c
@@ -31,8 +31,10 @@
 #include "ui/ui.h"
 
 /* For XWarpPointer *only* - see below */
+#ifndef GDK_WINDOWING_QUARTZ
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
+#endif
 
 static GdkCursor *nullpointer = NULL;
 
@@ -48,8 +50,10 @@ gtkmouse_reset_pointer( void )
    */
   GdkWindow *window = gtk_widget_get_window( gtkui_drawing_area );
 
+#ifndef GDK_WINDOWING_QUARTZ
   XWarpPointer( GDK_WINDOW_XDISPLAY( window ), None, 
                 GDK_WINDOW_XID( window ), 0, 0, 0, 0, 128, 128 );
+#endif
 }
 
 gboolean
