$NetBSD: patch-lib_stringlib.c,v 1.1 2020/11/22 11:36:32 nia Exp $

Argument to ctype functions must be unsigned char.

--- lib/stringlib.c.orig	2019-02-14 01:54:41.000000000 +0000
+++ lib/stringlib.c
@@ -38,7 +38,7 @@ Trim(string)
     register char *ptr;
     for (ptr = string; *ptr; ptr++);
 
-    while ((--ptr >= string) && isspace(*ptr));
+    while ((--ptr >= string) && isspace((unsigned char)*ptr));
 
     *(++ptr) = '\0';
 
