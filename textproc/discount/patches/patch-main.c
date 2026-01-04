$NetBSD: patch-main.c,v 1.2 2026/01/04 21:21:00 wiz Exp $

Make function prototypes match for GCC 14.

--- main.c.orig	2025-09-08 16:51:18.000000000 +0000
+++ main.c
@@ -107,8 +107,9 @@ char *external_formatter = 0;
 #define SENDER 1
 
 char *
-external_codefmt(char *src, int len, char *lang)
+external_codefmt(const char *src, const int len, void *arg3)
 {
+    char *lang = arg3;
     int child_status;
     int size, bufsize, curr;
     char *res;
