$NetBSD: patch-tools_xenpmd_xenpmd.c,v 1.1 2019/02/25 08:19:22 gutteridge Exp $

Elide format-truncation errors with GCC >= 7.

--- tools/xenpmd/xenpmd.c.orig	2018-07-09 13:47:19.000000000 +0000
+++ tools/xenpmd/xenpmd.c
@@ -100,7 +100,7 @@ FILE *get_next_battery_file(DIR *battery
 {
     FILE *file = 0;
     struct dirent *dir_entries;
-    char file_name[284];
+    char file_name[FILENAME_MAX];
     
     do 
     {
