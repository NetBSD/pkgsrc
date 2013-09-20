$NetBSD: patch-src_main.c,v 1.1 2013/09/20 11:51:44 obache Exp $

* PKGLOCALEDIR support

--- src/main.c.orig	2012-10-22 05:32:11.000000000 +0000
+++ src/main.c
@@ -146,7 +146,7 @@ main (gint argc, gchar *argv[])
 
     /* Init i18n messages */
     setlocale (LC_ALL, "zh_TW.utf8");
-    bindtextdomain(quote_me(PROJECT_NAME), quote_me(DATA_DIR) "/locale");
+    bindtextdomain(quote_me(PROJECT_NAME), "@PKGLOCALEDIR@/locale");
     textdomain(quote_me(PROJECT_NAME));
 
     context = g_option_context_new ("- ibus chewing engine component");
