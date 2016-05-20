$NetBSD: patch-libdbusmenu-glib_menuitem.c,v 1.1 2016/05/20 22:00:23 youri Exp $

Fix clang build.

--- libdbusmenu-glib/menuitem.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ libdbusmenu-glib/menuitem.c
@@ -974,7 +974,7 @@ dbusmenu_menuitem_find_id (DbusmenuMenui
 		}
 		return mi;
 	}
-	find_id_t find_id = {mi: NULL, id: id};
+	find_id_t find_id = {.mi = NULL, .id = id};
 	find_id_helper(mi, &find_id);
 	return find_id.mi;
 }
@@ -1712,7 +1712,7 @@ dbusmenu_menuitem_foreach (DbusmenuMenui
 
 	func(mi, data);
 	GList * children = dbusmenu_menuitem_get_children(mi);
-	foreach_struct_t foreach_data = {func: func, data: data};
+	foreach_struct_t foreach_data = {.func = func, .data = data};
 	g_list_foreach(children, foreach_helper, &foreach_data);
 	return;
 }
