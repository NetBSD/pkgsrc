$NetBSD: patch-src_Utility_ropeStuff.hh,v 1.2 2015/12/29 23:34:51 dholland Exp $

Don't use <rope> with clang, but fall back to <string>. Untested for
functionality.

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
