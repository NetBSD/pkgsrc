$NetBSD: patch-src_mongo_shell_linenoise__utf8.h,v 1.2 2015/08/26 05:03:00 fhajny Exp $

Use Boost swap instead of std. Fixes build on SunOS.
--- src/mongo/shell/linenoise_utf8.h.orig	2015-08-24 00:39:52.000000000 +0000
+++ src/mongo/shell/linenoise_utf8.h
@@ -27,6 +27,7 @@
  *    then also delete it in the license file.
  */
 
+#include <boost/core/swap.hpp>
 #include <boost/smart_ptr/scoped_array.hpp>
 #include <algorithm>
 #include <string.h>
@@ -173,9 +174,9 @@ struct UtfStringMixin {
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
 
