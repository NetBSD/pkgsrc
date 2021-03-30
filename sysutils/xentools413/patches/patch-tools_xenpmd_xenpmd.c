$NetBSD: patch-tools_xenpmd_xenpmd.c,v 1.2 2021/03/30 06:59:03 bouyer Exp $

Elide format-truncation errors with GCC >= 7.

--- tools/xenpmd/xenpmd.c.orig	2021-03-22 17:57:42.000000000 +0100
+++ tools/xenpmd/xenpmd.c	2021-03-29 22:09:44.630232427 +0200
@@ -101,7 +101,7 @@
 {
     FILE *file = 0;
     struct dirent *dir_entries;
-    char file_name[284];
+    char file_name[FILENAME_MAX];
     int ret;
     
     do 
