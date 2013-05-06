$NetBSD: patch-debug.hpp,v 1.1 2013/05/06 14:44:07 joerg Exp $

--- debug.hpp.orig	2013-04-30 22:44:05.000000000 +0000
+++ debug.hpp
@@ -33,8 +33,11 @@
 #define LUTOK_DEBUG_HPP
 
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+#else
 #include <tr1/memory>
-
+#endif
 
 namespace lutok {
 
@@ -56,7 +59,11 @@ class debug {
     struct impl;
 
     /// Pointer to the shared internal implementation.
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+    std::shared_ptr< impl > _pimpl;
+#else
     std::tr1::shared_ptr< impl > _pimpl;
+#endif
 
 public:
     debug(void);
