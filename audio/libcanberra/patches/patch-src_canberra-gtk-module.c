$NetBSD: patch-src_canberra-gtk-module.c,v 1.1 2017/12/10 17:57:42 adam Exp $

Fix for GTK compiled with Quartz support.

--- src/canberra-gtk-module.c.orig	2017-12-10 17:42:16.000000000 +0000
+++ src/canberra-gtk-module.c
@@ -25,8 +25,10 @@
 #endif
 
 #include <gtk/gtk.h>
+#ifndef GDK_WINDOWING_QUARTZ
 #include <gdk/gdkx.h>
 #include <X11/Xatom.h>
+#endif
 
 #include "canberra-gtk.h"
 
@@ -300,12 +302,13 @@ static SoundEventData* filter_sound_even
 }
 
 static gint window_get_desktop(GdkDisplay *d, GdkWindow *w) {
+        gint ret = -1;
+#ifndef GDK_WINDOWING_QUARTZ
         Atom type_return;
         gint format_return;
         gulong nitems_return;
         gulong bytes_after_return;
         guchar *data = NULL;
-        gint ret = -1;
 
         if (XGetWindowProperty(GDK_DISPLAY_XDISPLAY(d), GDK_WINDOW_XID(w),
                                gdk_x11_get_xatom_by_name_for_display(d, "_NET_WM_DESKTOP"),
@@ -323,17 +326,19 @@ static gint window_get_desktop(GdkDispla
 
         if (type_return != None && data != NULL)
                 XFree(data);
+#endif
 
         return ret;
 }
 
 static gint display_get_desktop(GdkDisplay *d) {
+        gint ret = -1;
+#ifndef GDK_WINDOWING_QUARTZ
         Atom type_return;
         gint format_return;
         gulong nitems_return;
         gulong bytes_after_return;
         guchar *data = NULL;
-        gint ret = -1;
 
         if (XGetWindowProperty(GDK_DISPLAY_XDISPLAY(d), DefaultRootWindow(GDK_DISPLAY_XDISPLAY(d)),
                                gdk_x11_get_xatom_by_name_for_display(d, "_NET_CURRENT_DESKTOP"),
@@ -352,17 +357,19 @@ static gint display_get_desktop(GdkDispl
 
         if (type_return != None && data != NULL)
                 XFree(data);
+#endif
 
         return ret;
 }
 
 static gboolean window_is_xembed(GdkDisplay *d, GdkWindow *w) {
+        gboolean ret = FALSE;
+#ifndef GDK_WINDOWING_QUARTZ
         Atom type_return;
         gint format_return;
         gulong nitems_return;
         gulong bytes_after_return;
         guchar *data = NULL;
-        gboolean ret = FALSE;
         Atom xembed;
 
         /* Gnome Panel applets are XEMBED windows. We need to make sure we
@@ -383,6 +390,7 @@ static gboolean window_is_xembed(GdkDisp
 
         if (type_return != None && data != NULL)
                 XFree(data);
+#endif
 
         return ret;
 }
