$NetBSD: patch-src_mongo_shell_linenoise__utf8.h,v 1.1 2019/06/28 16:30:56 gdt Exp $

Use Boost swap instead of std. Fixes build on SunOS.
--- src/mongo/shell/linenoise_utf8.h.orig	2016-01-05 18:31:44.000000000 +0000
+++ src/mongo/shell/linenoise_utf8.h
@@ -27,6 +27,7 @@
  *    then also delete it in the license file.
  */
 
+#include <boost/core/swap.hpp>
 #include <algorithm>
 #include <memory>
 #include <string.h>
@@ -178,9 +179,9 @@ struct UtfStringMixin {
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
 
