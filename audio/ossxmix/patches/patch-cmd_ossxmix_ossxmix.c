$NetBSD: patch-cmd_ossxmix_ossxmix.c,v 1.1 2024/05/21 10:35:42 nia Exp $

Looks slightly better on NetBSD with the "legacy" orientation.

--- cmd/ossxmix/ossxmix.c.orig	2024-05-21 10:30:26.876900607 +0000
+++ cmd/ossxmix/ossxmix.c
@@ -895,7 +895,11 @@ load_devinfo (int dev)
   GtkWidget *wid, *wid2, *gang, *rootwid = NULL, *pw = NULL, *frame, *box;
   GtkWidget **widgets;
   GtkObject *adjust, *adjust2;
+#ifdef __NetBSD__
+  gboolean change_orient = FALSE, ori, * orient;
+#else
   gboolean change_orient = TRUE, ori, * orient;
+#endif
   gboolean expand, use_layout_b = FALSE;
 
   mi.dev = dev;
