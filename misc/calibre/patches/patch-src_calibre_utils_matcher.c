$NetBSD: patch-src_calibre_utils_matcher.c,v 1.2 2022/01/09 15:43:51 rhialto Exp $

Fix build with ICU 68.

--- src/calibre/utils/matcher.c.orig	2020-02-21 03:27:12.000000000 +0000
+++ src/calibre/utils/matcher.c
@@ -15,7 +15,7 @@
 #define inline
 #endif
 
-typedef unsigned char bool;
+//typedef unsigned char bool;
 #define TRUE 1
 #define FALSE 0
 #define MAX(x, y) ((x > y) ? x : y)
