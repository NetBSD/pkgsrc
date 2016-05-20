$NetBSD: patch-libdbusmenu-glib_server.c,v 1.1 2016/05/20 22:00:23 youri Exp $

Fix clang build.

--- libdbusmenu-glib/server.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ libdbusmenu-glib/server.c
@@ -215,9 +215,9 @@ static gboolean   layout_update_idle    
 static GDBusNodeInfo *            dbusmenu_node_info = NULL;
 static GDBusInterfaceInfo *       dbusmenu_interface_info = NULL;
 static const GDBusInterfaceVTable dbusmenu_interface_table = {
-	method_call:    bus_method_call,
-	get_property:   bus_get_prop,
-	set_property:   NULL /* No properties that can be set */
+	.method_call =    bus_method_call,
+	.get_property =   bus_get_prop,
+	.set_property =   NULL /* No properties that can be set */
 };
 static method_table_t             dbusmenu_method_table[METHOD_COUNT];
 
