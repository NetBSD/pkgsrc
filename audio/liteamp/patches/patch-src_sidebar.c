$NetBSD: patch-src_sidebar.c,v 1.1 2012/07/03 18:20:29 joerg Exp $

--- src/sidebar.c.orig	2012-07-03 15:25:36.000000000 +0000
+++ src/sidebar.c
@@ -271,7 +271,7 @@ SidebarItem* sidebar_get_active_item(Sid
     GList* list;
     SidebarItem* item;
 
-    g_return_if_fail(IS_SIDEBAR(sidebar));
+    g_return_val_if_fail(IS_SIDEBAR(sidebar), NULL);
 
     list = sidebar->items;
     while(list != NULL && list->data != NULL) {
