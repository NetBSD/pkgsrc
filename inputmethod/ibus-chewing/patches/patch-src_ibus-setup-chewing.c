$NetBSD: patch-src_ibus-setup-chewing.c,v 1.1 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- src/ibus-setup-chewing.c.orig	2014-12-04 06:48:33.000000000 +0000
+++ src/ibus-setup-chewing.c
@@ -91,7 +91,7 @@ gint main(gint argc, gchar * argv[])
 
     /* Init i18n messages */
     setlocale(LC_ALL, "");
-    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(DATA_DIR) "/locale");
+    bindtextdomain(QUOTE_ME(PROJECT_NAME), QUOTE_ME(LOCALE_DIR));
     textdomain(QUOTE_ME(PROJECT_NAME));
 
     context = g_option_context_new("- ibus chewing engine setup");
