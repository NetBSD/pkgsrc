$NetBSD: patch-store_transaction.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- store/transaction.hpp.orig	2013-05-06 08:16:11.000000000 +0000
+++ store/transaction.hpp
@@ -37,7 +37,13 @@ extern "C" {
 }
 
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 #include <utility>
 
 #include "engine/test_program.hpp"
@@ -77,10 +83,10 @@ class results_iterator {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     friend class transaction;
-    results_iterator(std::tr1::shared_ptr< impl >);
+    results_iterator(shared_ptr< impl >);
 
 public:
     ~results_iterator(void);
@@ -106,7 +112,7 @@ class transaction {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     friend class backend;
     transaction(backend&);
