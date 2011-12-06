$NetBSD: patch-mytypes.h,v 1.1 2011/12/06 19:51:47 joerg Exp $

--- mytypes.h.orig	2011-12-06 16:32:43.000000000 +0000
+++ mytypes.h
@@ -7,7 +7,7 @@
 
 /* some types and macros I miss in C89 */
 
-typedef enum { false, true } bool;
+#include <stdbool.h>
 
 #define Min(x,y) ((x)<=(y)?(x):(y))
 #define Max(x,y) ((x)>=(y)?(x):(y))
