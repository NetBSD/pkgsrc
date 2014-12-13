$NetBSD: patch-src_generate-gconf-schemas.c,v 1.2 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- src/generate-gconf-schemas.c.orig	2014-12-09 06:13:50.000000000 +0000
+++ src/generate-gconf-schemas.c
@@ -172,7 +172,7 @@ int main(gint argc, gchar * argv[])
 
     /* Init i18n messages */
     setlocale(LC_ALL, "");
-    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(DATA_DIR) "/locale");
+    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(LOCALE_DIR));
     textdomain(QUOTE_ME(PROJECT_NAME));
 
     context = g_option_context_new("schemasFile");
