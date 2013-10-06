$NetBSD: patch-plugins_gdb_preferences.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/gdb/preferences.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/gdb/preferences.c
@@ -125,11 +125,9 @@ gdb_check_register_function (PreferenceD
 		 * implementation details.
 		 * The register function is an additional function in the script. It defines
 		 * which function is used for each type of variables. */
-		msg = g_strdup_printf(_("The register function hasn't been found automatically in the following pretty printer files:\n"
+		anjuta_util_dialog_warning (GTK_WINDOW (gtk_widget_get_toplevel (GTK_WIDGET (dlg->treeview))), _("The register function hasn't been found automatically in the following pretty printer files:\n"
 								"%s\nYou need to fill yourself the register function columns before enabling the rows. "
 								"Most of the time the register function name contains the word \"register\"."), list->str);
-		anjuta_util_dialog_warning (GTK_WINDOW (gtk_widget_get_toplevel (GTK_WIDGET (dlg->treeview))), msg);
-		g_free (msg);
 		g_string_free (list, TRUE);
 	}
 }
