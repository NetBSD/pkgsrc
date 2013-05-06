$NetBSD: patch-state.hpp,v 1.1 2013/05/06 14:44:07 joerg Exp $

--- state.hpp.orig	2013-04-30 22:43:07.000000000 +0000
+++ state.hpp
@@ -33,7 +33,12 @@
 #define LUTOK_STATE_HPP
 
 #include <string>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 namespace lutok {
 
@@ -72,7 +77,11 @@ class state {
     struct impl;
 
     /// Pointer to the shared internal implementation.
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+    std::shared_ptr< impl > _pimpl;
+#else
     std::tr1::shared_ptr< impl > _pimpl;
+#endif
 
     void* new_userdata_voidp(const size_t);
     void* to_userdata_voidp(const int);
