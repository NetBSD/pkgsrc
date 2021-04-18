$NetBSD: patch-tools_libs_util_libxlu_pci.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- ./tools/libs/util/libxlu_pci.c.orig	2021-04-17 22:17:52.998629860 +0200
+++ ./tools/libs/util/libxlu_pci.c	2021-04-17 22:18:06.194127140 +0200
@@ -19,7 +19,7 @@
     int n;
 
     /* Count occurrences of ':' to detrmine presence/absence of the 'domain' */
-    while (isxdigit(*ptr) || *ptr == ':') {
+    while (isxdigit((unsigned char)*ptr) || *ptr == ':') {
         if (*ptr == ':')
             colons++;
         ptr++;
