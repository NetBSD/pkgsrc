$NetBSD: patch-Utilities_cmjsoncpp_src_lib__json_json__writer.cpp,v 1.2 2015/07/26 23:10:47 wiz Exp $

iso/math_c99.h defines isfinite already on SunOS.

--- Utilities/cmjsoncpp/src/lib_json/json_writer.cpp.orig	2015-07-23 13:59:36.000000000 +0000
+++ Utilities/cmjsoncpp/src/lib_json/json_writer.cpp
@@ -24,7 +24,9 @@
 // Solaris
 #if defined(__sun)
 # include <ieeefp.h>
-# define isfinite finite
+# if !defined(isfinite)
+#  define isfinite finite
+# endif
 #endif
 
 // AIX
