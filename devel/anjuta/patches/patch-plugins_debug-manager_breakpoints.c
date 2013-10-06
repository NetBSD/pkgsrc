$NetBSD: patch-plugins_debug-manager_breakpoints.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/debug-manager/breakpoints.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/debug-manager/breakpoints.c
@@ -445,7 +445,10 @@ breakpoints_dbase_update_in_treeview (Br
 		filename = bi->bp.function;
 		format = filename == NULL ? "??" : "%s";
 	}
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 	location = g_strdup_printf (format, filename, bi->bp.line, bi->bp.function);
+#pragma GCC diagnostic pop
 	if (bi->bp.id == 0)
 	{
 		pass = g_strdup_printf ("%d", bi->bp.ignore);
@@ -474,7 +477,10 @@ breakpoints_dbase_update_in_treeview (Br
 	{
 		format = "permanent (%d)";
 	}
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 	state = g_strdup_printf (format, bi->bp.id);
+#pragma GCC diagnostic pop
 
 	gtk_list_store_set (bd->model, &bi->iter,
 						ENABLED_COLUMN, bi->bp.enable,
