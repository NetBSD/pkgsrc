$NetBSD: patch-tools_libs_light_libxl.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- tools/libs/light/libxl.c.orig	2021-04-17 22:11:04.304715386 +0200
+++ tools/libs/light/libxl.c	2021-04-17 22:12:29.062613549 +0200
@@ -673,7 +673,7 @@
         goto out;
     }
 
-    while (isblank(*params))
+    while (isblank((unsigned char)*params))
         params++;
 
     for (par = params; *par; par = end) {
@@ -703,7 +703,7 @@
             goto out;
         }
 
-        while (isblank(*end))
+        while (isblank((unsigned char)*end))
             end++;
     }
 
