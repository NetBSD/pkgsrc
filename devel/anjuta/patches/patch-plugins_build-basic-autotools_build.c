$NetBSD: patch-plugins_build-basic-autotools_build.c,v 1.4 2019/09/15 17:55:09 nia Exp $

--- plugins/build-basic-autotools/build.c.orig	2018-10-22 19:25:42.000000000 +0000
+++ plugins/build-basic-autotools/build.c
@@ -218,7 +218,7 @@ directory_has_file (GFile *dir, const gc
 }
 
 static gchar*
-shell_quotef (const gchar *format,...)
+G_GNUC_PRINTF(1,2) shell_quotef (const gchar *format,...)
 {
 	va_list args;
 	gchar *str;
@@ -575,7 +575,7 @@ build_save_distclean_and_execute_command
 
 		// Need to run make clean before
 		if (!anjuta_util_dialog_boolean_question (GTK_WINDOW (ANJUTA_PLUGIN (bplugin)->shell), FALSE,
-		    _("Before using this new configuration, the default one needs to be removed. Do you want to do that?"), NULL))
+		    _("Before using this new configuration, the default one needs to be removed. Do you want to do that?")))
 		{
 			if (err)
 				*err = g_error_new (ianjuta_builder_error_quark (),
