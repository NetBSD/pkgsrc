$NetBSD: patch-src_mongo_shell_linenoise__utf8.h,v 1.1 2023/07/29 11:51:15 adam Exp $

Use Boost swap instead of std. Fixes build on SunOS.

--- src/mongo/shell/linenoise_utf8.h.orig	2019-01-30 14:26:33.000000000 +0000
+++ src/mongo/shell/linenoise_utf8.h
@@ -29,6 +29,7 @@
  *    it in the license file.
  */
 
+#include <boost/core/swap.hpp>
 #include <algorithm>
 #include <memory>
 #include <string.h>
@@ -176,9 +177,9 @@ struct UtfStringMixin {
     }
 
     void swap(UtfStringMixin& other) {
-        std::swap(_len, other._len);
-        std::swap(_cap, other._cap);
-        std::swap(_chars, other._chars);
+        boost::swap(_len, other._len);
+        boost::swap(_cap, other._cap);
+        boost::swap(_chars, other._chars);
         _str.swap(other._str);
     }
 
