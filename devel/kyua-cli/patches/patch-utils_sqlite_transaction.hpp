$NetBSD: patch-utils_sqlite_transaction.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/sqlite/transaction.hpp.orig	2013-05-06 08:10:32.000000000 +0000
+++ utils/sqlite/transaction.hpp
@@ -32,7 +32,14 @@
 #if !defined(UTILS_SQLITE_TRANSACTION_HPP)
 #define UTILS_SQLITE_TRANSACTION_HPP
 
+#include <ciso646>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 namespace utils {
 namespace sqlite {
@@ -49,7 +56,7 @@ class transaction {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     explicit transaction(database&);
     friend class database;
