$NetBSD: patch-src_generate-gconf-schemas.c,v 1.1 2013/10/08 12:06:23 obache Exp $

* PKGLOCALEDIR support

--- src/generate-gconf-schemas.c.orig	2012-10-22 05:32:11.000000000 +0000
+++ src/generate-gconf-schemas.c
@@ -41,7 +41,7 @@ int main (gint argc, gchar *argv[])
 
     /* Init i18n messages */
     setlocale (LC_ALL, "");
-    bindtextdomain(quote_me(PROJECT_NAME), quote_me(DATA_DIR) "/locale");
+    bindtextdomain(quote_me(PROJECT_NAME), quote_me(LOCALE_DIR));
     textdomain(quote_me(PROJECT_NAME));
 
     context = g_option_context_new("schemasFile");
