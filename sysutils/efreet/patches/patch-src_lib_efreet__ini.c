$NetBSD: patch-src_lib_efreet__ini.c,v 1.1 2025/10/29 00:30:08 gutteridge Exp $

Use ctype.h correctly.

--- src/lib/efreet_ini.c.orig	2013-07-29 14:22:54.000000000 +0000
+++ src/lib/efreet_ini.c
@@ -128,7 +128,7 @@ efreet_ini_parse(const char *file)
             ;
 
         /* check for all white space */
-        while (isspace(line_start[0]) && (line_length > 0))
+        while (isspace((unsigned char)line_start[0]) && (line_length > 0))
         {
             line_start++;
             line_length--;
@@ -195,15 +195,15 @@ efreet_ini_parse(const char *file)
 
             /* trim whitespace from end of key */
             for (key_end = sep - 1;
-                    (key_end > 0) && isspace(line_start[key_end]); --key_end)
+                    (key_end > 0) && isspace((unsigned char)line_start[key_end]); --key_end)
                 ;
 
-            if (!isspace(line_start[key_end])) key_end++;
+            if (!isspace((unsigned char)line_start[key_end])) key_end++;
 
             /* trim whitespace from start of value */
             for (value_start = sep + 1;
                  (value_start < line_length) &&
-                 isspace(line_start[value_start]); ++value_start)
+                 isspace((unsigned char)line_start[value_start]); ++value_start)
                 ;
 
             /* trim \n off of end of value */
