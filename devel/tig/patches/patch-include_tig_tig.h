$NetBSD: patch-include_tig_tig.h,v 1.2 2022/01/12 21:39:33 fcambus Exp $

Macro safety fix.

--- include/tig/tig.h.orig	2022-01-11 18:50:37.000000000 +0000
+++ include/tig/tig.h
@@ -125,7 +125,7 @@
 #define MIN(x, y)	((x) < (y) ? (x) :  (y))
 #define MAX(x, y)	((x) > (y) ? (x) :  (y))
 
-#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
+#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))
 #define STRING_SIZE(x)	(sizeof(x) - 1)
 
 #define SIZEOF_STR	1024	/* Default string size. */
