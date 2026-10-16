$NetBSD: patch-src_adapter_main.cpp,v 1.1 2026/10/16 17:53:01 ktnb Exp $

Don't die when file doesn't exist

--- src/adapter/main.cpp.orig	2026-10-16 17:24:47.983164281 +0000
+++ src/adapter/main.cpp
@@ -167,8 +167,9 @@ static void parse_option() {
 
    file_name = option_get_string("OptionFile");
 
-   file = fopen(file_name,"r");
-   if (file == NULL) my_fatal( "Can't open file \"%s\": %s - using defaults\n",file_name,strerror(errno));
+   file = file_name ? fopen(file_name,"r") : NULL;;
+   if (file == NULL && file_name != NULL)
+     my_log( "Can't open file \"%s\": %s - using defaults\n",file_name,strerror(errno));
 
    // PolyGlot options (assumed first)
 
