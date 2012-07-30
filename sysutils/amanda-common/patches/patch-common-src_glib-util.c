$NetBSD: patch-common-src_glib-util.c,v 1.1 2012/07/30 07:21:11 sbd Exp $

Rename g_queue_free_full to stop conflict with newer glib.

--- common-src/glib-util.c.orig	2012-02-21 11:36:51.000000000 +0000
+++ common-src/glib-util.c
@@ -120,7 +120,7 @@ void slist_free_full(GSList * list, GDes
 }
 #endif
 
-void g_queue_free_full(GQueue * queue) {
+void am_g_queue_free_full(GQueue * queue) {
     while (!g_queue_is_empty(queue)) {
         gpointer data;
         data = g_queue_pop_head(queue);
