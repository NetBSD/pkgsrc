$NetBSD: patch-src_canberra-gtk.c,v 1.1 2017/12/10 17:57:42 adam Exp $

Fix for GTK compiled with Quartz support.

--- src/canberra-gtk.c.orig	2017-12-10 17:38:26.000000000 +0000
+++ src/canberra-gtk.c
@@ -26,8 +26,10 @@
 
 #include <gtk/gtk.h>
 #include <gdk/gdk.h>
+#ifndef GDK_WINDOWING_QUARTZ
 #include <gdk/gdkx.h>
 #include <X11/Xatom.h>
+#endif
 
 #include "canberra.h"
 #include "canberra-gtk.h"
@@ -178,12 +180,13 @@ static GtkWindow* get_toplevel(GtkWidget
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
@@ -201,6 +204,7 @@ static gint window_get_desktop(GdkDispla
 
         if (type_return != None && data != NULL)
                 XFree(data);
+#endif
 
         return ret;
 }
@@ -258,6 +262,11 @@ int ca_gtk_proplist_set_for_widget(ca_pr
                 GdkDisplay *display = NULL;
                 gint x = -1, y = -1, width = -1, height = -1, screen_width = -1, screen_height = -1;
 
+#ifdef GDK_WINDOWING_QUARTZ
+                dw = gtk_widget_get_window(GTK_WIDGET(w));
+                display = gtk_widget_get_display(GTK_WIDGET(w));
+                screen = gtk_widget_get_screen(GTK_WIDGET(w));
+#else
                 if ((dw = gtk_widget_get_window(GTK_WIDGET(w))))
                         if ((ret = ca_proplist_setf(p, CA_PROP_WINDOW_X11_XID, "%lu", (unsigned long) GDK_WINDOW_XID(dw))) < 0)
                                 return ret;
@@ -285,6 +294,7 @@ int ca_gtk_proplist_set_for_widget(ca_pr
                                 if ((ret = ca_proplist_setf(p, CA_PROP_WINDOW_X11_MONITOR, "%i", gdk_screen_get_monitor_at_window(screen, dw))) < 0)
                                         return ret;
                 }
+#endif
 
                 /* FIXME, this might cause a round trip */
 
