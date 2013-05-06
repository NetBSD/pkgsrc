$NetBSD: patch-utils_sqlite_statement.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/sqlite/statement.hpp.orig	2013-05-06 08:04:34.000000000 +0000
+++ utils/sqlite/statement.hpp
@@ -40,7 +40,13 @@ extern "C" {
 }
 
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 namespace utils {
 namespace sqlite {
@@ -92,7 +98,7 @@ class statement {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     statement(database&, void*);
     friend class database;
