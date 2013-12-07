$NetBSD: patch-plugins_debug-manager_breakpoints.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

--- plugins/debug-manager/breakpoints.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/debug-manager/breakpoints.c
@@ -423,6 +423,8 @@ breakpoints_dbase_clear_in_editor (Break
 	}
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static void
 breakpoints_dbase_update_in_treeview (BreakpointsDBase *bd, BreakpointItem *bi)
 {
@@ -490,6 +492,7 @@ breakpoints_dbase_update_in_treeview (Br
 	g_free (location);
 	g_free (adr);
 }
+#pragma GCC diagnostic pop
 
 static void
 breakpoints_dbase_breakpoint_removed (BreakpointsDBase *bd, BreakpointItem *bi)
