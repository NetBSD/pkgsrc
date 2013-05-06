$NetBSD: patch-utils_sqlite_database.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/sqlite/database.hpp.orig	2013-05-06 07:46:57.000000000 +0000
+++ utils/sqlite/database.hpp
@@ -40,7 +40,13 @@ extern "C" {
 }
 
 #include <cstddef>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "utils/fs/path.hpp"
 
@@ -79,7 +85,7 @@ class database {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     friend class database_c_gate;
     database(void*, const bool);
