$NetBSD: patch-plugins_build-basic-autotools_build.c,v 1.2.20.1 2016/05/11 15:33:29 bsiegert Exp $

--- plugins/build-basic-autotools/build.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/build-basic-autotools/build.c
@@ -216,7 +216,7 @@ directory_has_file (GFile *dir, const gc
 }
 
 static gchar*
-shell_quotef (const gchar *format,...)
+G_GNUC_PRINTF(1,2) shell_quotef (const gchar *format,...)
 {
 	va_list args;
 	gchar *str;
@@ -524,7 +524,7 @@ build_save_distclean_and_execute_command
 
 		// Need to run make clean before
 		if (!anjuta_util_dialog_boolean_question (GTK_WINDOW (ANJUTA_PLUGIN (bplugin)->shell), FALSE,
-		    _("Before using this new configuration, the default one needs to be removed. Do you want to do that ?"), NULL))
+		    _("Before using this new configuration, the default one needs to be removed. Do you want to do that ?")))
 		{
 			if (err)
 				*err = g_error_new (ianjuta_builder_error_quark (),
