$NetBSD: patch-tools_misc_xenhypfs.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- tools/misc/xenhypfs.c.orig	2021-04-17 22:22:30.893118826 +0200
+++ tools/misc/xenhypfs.c	2021-04-17 22:23:04.525580088 +0200
@@ -22,7 +22,7 @@
     char *c;
 
     for (c = string; *c; c++) {
-        if (isgraph(*c) || isspace(*c))
+        if (isgraph((unsigned char)*c) || isspace((unsigned char)*c))
             printf("%c", *c);
         else
             printf("\\x%02x", *c);
