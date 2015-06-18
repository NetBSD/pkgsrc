$NetBSD: patch-include_mutils_mutils.h,v 1.1 2015/06/18 06:17:33 dholland Exp $

Sun Studio doesn't understand __const.

--- include/mutils/mutils.h~	2015-06-18 06:08:36.000000000 +0000
+++ include/mutils/mutils.h
@@ -23,7 +23,7 @@
 
 #include <mutils/mincludes.h>
 
-#if defined(const)
+#if defined(const) || (defined(__sun) && !defined(__GNUC__))
 #define __const const
 #endif 
 
