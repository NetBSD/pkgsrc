$NetBSD: patch-tools_toolutil_pkg_gencmn.c,v 1.1 2011/06/02 07:06:11 adam Exp $

Avoid out of memory.

--- tools/toolutil/pkg_gencmn.c.orig	2011-06-02 06:18:25.000000000 +0000
+++ tools/toolutil/pkg_gencmn.c
@@ -18,7 +18,7 @@
 #include "putilimp.h"
 #include "pkg_gencmn.h"
 
-#define STRING_STORE_SIZE 100000
+#define STRING_STORE_SIZE 131072
 
 #define COMMON_DATA_NAME U_ICUDATA_NAME
 #define DATA_TYPE "dat"
