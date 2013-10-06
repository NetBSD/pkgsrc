$NetBSD: patch-libanjuta_anjuta-utils.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- libanjuta/anjuta-utils.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ libanjuta/anjuta-utils.c
@@ -145,7 +145,7 @@ anjuta_util_copy_file (const gchar * src
 free: if (error)
 	{
 		if (show_error)
-			anjuta_util_dialog_error_system (NULL, error->code,
+			anjuta_util_dialog_error_system (NULL, error->code, "%s",
 											 error->message);
 
 		g_warning ("%s", error->message);
