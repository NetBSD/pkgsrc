$NetBSD: patch-src_Utility_ropeStuff.hh,v 1.1 2013/11/29 18:30:10 joerg Exp $

--- src/Utility/ropeStuff.hh.orig	2005-10-06 19:59:42.000000000 +0000
+++ src/Utility/ropeStuff.hh
@@ -25,6 +25,11 @@
 //
 #ifndef _ropeStuff_hh_
 #define _ropeStuff_hh_
+#include <cstddef>
+#ifdef _LIBCPP_VERSION
+#include <string>
+typedef std::string crope;
+#else
 #ifdef __GNUC__
   #if __GNUC__ < 3
     #include <rope.h>
@@ -50,3 +55,5 @@
 #include <rope>
 #endif
 #endif
+
+#endif
