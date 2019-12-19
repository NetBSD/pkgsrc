$NetBSD: patch-server_tools.c,v 1.1 2019/12/19 22:14:46 joerg Exp $

--- server/tools.c.orig	2019-12-19 20:55:27.470742715 +0000
+++ server/tools.c
@@ -41,7 +41,7 @@
 int charstar_to_int(const char * s)
 {
         int number = 0;
-        while (*s && isdigit(*s)) {
+        while (*s && isdigit((unsigned char)*s)) {
                 number = (number * 10) + (*s - '0');
                 s++;
         }
