$NetBSD: patch-src_main.c,v 1.1 2013/10/23 12:15:21 obache Exp $

* Set PKGLOCALEDIR as default locale dir.

--- src/main.c.orig	2011-01-25 23:55:35.000000000 +0000
+++ src/main.c
@@ -36,7 +36,7 @@ int main(int argc, char* argv[])
 
 	const gchar * icon_dir = NULL;
 
-	const gchar * locale_dir = NULL;
+	const gchar * locale_dir = "@_PKGLOCALEDIR@";
 
 
 	setlocale(LC_ALL, "");
