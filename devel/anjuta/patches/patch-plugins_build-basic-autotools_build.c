$NetBSD: patch-plugins_build-basic-autotools_build.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/build-basic-autotools/build.c.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/build-basic-autotools/build.c
@@ -216,7 +216,7 @@ directory_has_file (GFile *dir, const gc
 }
 
 static gchar*
-shell_quotef (const gchar *format,...)
+shell_quotef (const gchar *format,...) G_GNUC_PRINTF(1,2)
 {
 	va_list args;
 	gchar *str;
