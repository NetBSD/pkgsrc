$NetBSD: patch-main.c,v 1.1 2025/09/29 20:38:04 mrg Exp $

Make function prototypes match for GCC 14.

--- main.c.orig	2023-08-23 01:09:27.000000000 -0700
+++ main.c	2025-09-25 12:07:41.131761165 -0700
@@ -100,8 +100,9 @@
 }
 
 char *
-external_codefmt(char *src, int len, char *lang)
+external_codefmt(const char *src, const int len, void *arg3)
 {
+    char *lang = arg3;
     int extra = 0;
     int i, x;
     char *res;
