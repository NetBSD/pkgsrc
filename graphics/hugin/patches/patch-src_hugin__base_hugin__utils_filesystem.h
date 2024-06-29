$NetBSD: patch-src_hugin__base_hugin__utils_filesystem.h,v 1.1 2024/06/29 02:42:00 markd Exp $

Fixed deprecated boost::filesystem::copy_option enum
https://sourceforge.net/p/hugin/hugin/ci/4d081490b48aaff820cee7601b8624b37b652c06/

--- src/hugin_base/hugin_utils/filesystem.h.orig	2023-05-08 18:19:14.000000000 +0000
+++ src/hugin_base/hugin_utils/filesystem.h
@@ -64,6 +64,12 @@
     #endif
     #include <boost/filesystem.hpp>
     namespace fs = boost::filesystem;
-    #define OVERWRITE_EXISTING boost::filesystem::copy_option::overwrite_if_exists
+    #if BOOST_VERSION>=107400
+      // in Boost 1.74 and later filesystem::copy_option is deprecated
+      // use filesystem::copy_options instead
+      #define OVERWRITE_EXISTING boost::filesystem::copy_options::overwrite_existing
+    #else
+      #define OVERWRITE_EXISTING boost::filesystem::copy_option::overwrite_if_exists
+    #endif
 #endif
 #endif // _HUGIN_UTILS_FILESYSTEM_H
