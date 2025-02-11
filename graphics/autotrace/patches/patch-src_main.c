$NetBSD: patch-src_main.c,v 1.1 2025/02/11 10:56:47 ryoon Exp $

* getopt_long_only() is not very portable.

--- src/main.c.orig	2025-01-03 14:24:09.985835225 +0000
+++ src/main.c
@@ -280,7 +280,7 @@ static char *read_command_line(int argc,
 
   while (TRUE) {
 
-    g = getopt_long_only(argc, argv, "", long_options, &option_index);
+    g = getopt_long(argc, argv, "", long_options, &option_index);
 
     if (g == EOF)
       break;
