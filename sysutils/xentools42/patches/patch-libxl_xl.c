$NetBSD: patch-libxl_xl.c,v 1.1 2015/10/19 16:40:41 joerg Exp $

Fix obviously incorrect logic.

--- libxl/xl.c.orig	2015-10-09 22:54:31.000000000 +0000
+++ libxl/xl.c
@@ -80,7 +80,7 @@ static void parse_global_config(const ch
         lockfile = strdup(XL_LOCK_FILE);
     }
 
-    if (!lockfile < 0) {
+    if (lockfile == 0) {
         fprintf(stderr, "failed to allocate lockdir \n");
         exit(1);
     }
