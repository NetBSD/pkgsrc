$NetBSD: patch-plugins_build-basic-autotools_build.c,v 1.2 2013/12/07 23:47:02 dholland Exp $

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
