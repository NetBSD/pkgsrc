$NetBSD: patch-tools_libs_light_libxl_pci.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- tools/libs/light/libxl_pci.c.orig	2021-04-17 22:15:01.075399964 +0200
+++ tools/libs/light/libxl_pci.c	2021-04-17 22:15:30.482517194 +0200
@@ -777,7 +777,7 @@
         }
 
         for (i = 0; i < n; i++) {
-            if (!isgraph(name[i])) {
+            if (!isgraph((unsigned char)name[i])) {
                 LOG(ERROR, "Names may only include printable characters");
                 return ERROR_FAIL;
             }
