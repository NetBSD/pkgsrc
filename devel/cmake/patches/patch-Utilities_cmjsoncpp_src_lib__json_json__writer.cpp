$NetBSD: patch-Utilities_cmjsoncpp_src_lib__json_json__writer.cpp,v 1.1 2015/06/12 18:42:25 richard Exp $

iso/math_c99.h defines isfinite already on SunOS.

--- Utilities/cmjsoncpp/src/lib_json/json_writer.cpp.orig	2015-06-01 15:56:11.000000000 +0000
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
 
 // Ancient glibc
