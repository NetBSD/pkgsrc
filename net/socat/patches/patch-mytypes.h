$NetBSD: patch-mytypes.h,v 1.2 2014/09/07 23:24:56 rodent Exp $

Use stdbool.

--- mytypes.h.orig	2010-10-06 07:25:30.000000000 +0000
+++ mytypes.h
@@ -7,7 +7,7 @@
 
 /* some types and macros I miss in C89 */
 
-typedef enum { false, true } bool;
+#include <stdbool.h>
 
 #define Min(x,y) ((x)<=(y)?(x):(y))
 #define Max(x,y) ((x)>=(y)?(x):(y))
