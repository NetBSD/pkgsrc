$NetBSD: patch-src_main.c,v 1.4 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- src/main.c.orig	2014-12-09 06:13:50.000000000 +0000
+++ src/main.c
@@ -162,7 +162,7 @@ int main(gint argc, gchar * argv[])
 
     /* Init i18n messages */
     setlocale(LC_ALL, "");
-    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(DATA_DIR) "/locale");
+    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(LOCALE_DIR));
     textdomain(QUOTE_ME(PROJECT_NAME));
     determine_locale();
 
