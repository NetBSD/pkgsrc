$NetBSD: patch-src_mongo_shell_linenoise__utf8.h,v 1.1 2015/05/02 08:10:33 ryoon Exp $

Use Boost swap instead of std. Fixes build on SunOS.
--- src/mongo/shell/linenoise_utf8.h.orig	2015-04-08 20:28:08.000000000 +0000
+++ src/mongo/shell/linenoise_utf8.h
@@ -27,6 +27,7 @@
  *    then also delete it in the license file.
  */
 
+#include <boost/core/swap.hpp>
 #include <boost/smart_ptr/scoped_array.hpp>
 #include <algorithm>
 #include <string.h>
@@ -155,9 +156,9 @@ struct UtfStringMixin {
     size_t chars() const { return _chars; }
 
     void swap( UtfStringMixin& other ) {
-        std::swap( _len, other._len );
-        std::swap( _cap, other._cap );
-        std::swap( _chars, other._chars );
+        boost::swap( _len, other._len );
+        boost::swap( _cap, other._cap );
+        boost::swap( _chars, other._chars );
         _str.swap( other._str );
     }
 
