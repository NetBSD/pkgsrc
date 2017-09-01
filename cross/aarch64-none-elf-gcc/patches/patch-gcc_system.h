$NetBSD: patch-gcc_system.h,v 1.1 2017/09/01 20:56:43 jmcneill Exp $

--- gcc/system.h.orig	2015-01-05 12:33:28.000000000 +0000
+++ gcc/system.h
@@ -44,6 +44,9 @@ along with GCC; see the file COPYING3.  
 #endif
 
 #include <stdio.h>
+#ifdef __cplusplus
+# include <cstdio>
+#endif
 
 /* Define a generic NULL if one hasn't already been defined.  */
 #ifndef NULL
