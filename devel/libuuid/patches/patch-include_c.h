$NetBSD: patch-include_c.h,v 1.1 2018/01/02 10:24:06 jperkin Exp $

Add NAME_MAX compat.

--- include/c.h.orig	2017-09-27 09:05:13.694361539 +0000
+++ include/c.h
@@ -29,6 +29,10 @@
 # define LOGIN_NAME_MAX 256
 #endif
 
+#ifndef NAME_MAX
+# define NAME_MAX PATH_MAX
+#endif
+
 /*
  * Compiler-specific stuff
  */
