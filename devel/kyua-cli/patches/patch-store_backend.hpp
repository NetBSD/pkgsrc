$NetBSD: patch-store_backend.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- store/backend.hpp.orig	2013-05-06 07:36:42.000000000 +0000
+++ store/backend.hpp
@@ -32,7 +32,14 @@
 #if !defined(STORE_BACKEND_HPP)
 #define STORE_BACKEND_HPP
 
+#include <ciso646>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 namespace utils {
 namespace fs {
@@ -72,7 +79,7 @@ class backend {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     friend class metadata;
 
