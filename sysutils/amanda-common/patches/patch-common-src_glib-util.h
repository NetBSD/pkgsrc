$NetBSD: patch-common-src_glib-util.h,v 1.1 2012/07/30 07:21:11 sbd Exp $

Rename g_queue_free_full to stop conflict with newer glib.

--- common-src/glib-util.h.orig	2012-02-21 11:36:51.000000000 +0000
+++ common-src/glib-util.h
@@ -72,7 +72,7 @@ void slist_free_full(GSList * list, GDes
 
 /* These functions all take a GLib container, and call free() on all the
  * pointers in the container before free()ing the container itself. */
-void g_queue_free_full(GQueue * queue);
+void am_g_queue_free_full(GQueue * queue);
 void g_ptr_array_free_full(GPtrArray * array);
 
 /* g_value_compare() does what you expect. It returns TRUE if and
