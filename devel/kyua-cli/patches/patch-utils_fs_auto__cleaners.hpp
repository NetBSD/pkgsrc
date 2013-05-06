$NetBSD: patch-utils_fs_auto__cleaners.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/fs/auto_cleaners.hpp.orig	2013-05-06 08:10:18.000000000 +0000
+++ utils/fs/auto_cleaners.hpp
@@ -33,7 +33,13 @@
 #define UTILS_FS_AUTO_CLEANERS_HPP
 
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "utils/fs/path.hpp"
 
@@ -48,7 +54,7 @@ namespace fs {
 class auto_directory {
     struct impl;
     /// Reference-counted, shared implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
 public:
     explicit auto_directory(const path&);
@@ -68,7 +74,7 @@ public:
 class auto_file {
     struct impl;
     /// Reference-counted, shared implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
 public:
     explicit auto_file(const path&);
