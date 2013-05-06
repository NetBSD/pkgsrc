$NetBSD: patch-engine_action.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- engine/action.hpp.orig	2013-05-06 08:08:05.000000000 +0000
+++ engine/action.hpp
@@ -33,7 +33,13 @@
 #define ENGINE_ACTION_HPP
 
 #include <ostream>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 namespace engine {
 
@@ -50,7 +56,7 @@ class action {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
 public:
     explicit action(const context&);
