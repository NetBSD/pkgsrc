$NetBSD: patch-gtk-v2-src-metaserver.c,v 1.1 2011/08/20 15:31:33 joerg Exp $

--- gtk-v2/src/metaserver.c.orig	2011-08-20 13:51:04.000000000 +0000
+++ gtk-v2/src/metaserver.c
@@ -60,7 +60,8 @@ gboolean metaserver_selection_func (
     return TRUE;
 }
 
-get_metaserver()
+void
+get_metaserver(void)
 {
     static int has_init=0;
     GtkTreeIter iter;
