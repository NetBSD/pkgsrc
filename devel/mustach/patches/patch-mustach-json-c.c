$NetBSD: patch-mustach-json-c.c,v 1.1 2019/12/25 17:34:32 sjmulder Exp $

Include alloca.h on Solaris-likes to fix the build.

--- mustach-json-c.c.orig	2019-09-19 08:20:36.000000000 +0000
+++ mustach-json-c.c
@@ -21,6 +21,9 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef __sun
+# include <alloca.h>
+#endif
 
 #include <json-c/json.h>
 
