$NetBSD: patch-src_generate-gsettings-schemas.c,v 1.1 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- src/generate-gsettings-schemas.c.orig	2014-12-09 06:13:50.000000000 +0000
+++ src/generate-gsettings-schemas.c
@@ -67,7 +67,7 @@ int main(gint argc, gchar * argv[])
 
     /* Init i18n messages */
     setlocale(LC_ALL, "");
-    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(DATA_DIR) "/locale");
+    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(LOCALE_DIR));
     textdomain(QUOTE_ME(PROJECT_NAME));
 
     context = g_option_context_new("schemasFile");
