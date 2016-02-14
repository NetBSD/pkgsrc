$NetBSD: patch-zathura_main.c,v 1.1 2016/02/14 13:43:21 leot Exp $

synctex_editor parameter is passed to init_zathura() inconditionally if
WITH_SYNCTEX (or without). Declare it in both cases.

--- zathura/main.c.orig	2015-12-21 10:19:18.000000000 +0000
+++ zathura/main.c
@@ -135,8 +135,8 @@ main(int argc, char* argv[])
   gchar* plugin_path    = NULL;
   gchar* loglevel       = NULL;
   gchar* password       = NULL;
-#ifdef WITH_SYNCTEX
   gchar* synctex_editor = NULL;
+#ifdef WITH_SYNCTEX
   gchar* synctex_fwd    = NULL;
 #endif
   gchar* mode           = NULL;
