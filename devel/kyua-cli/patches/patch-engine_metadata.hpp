$NetBSD: patch-engine_metadata.hpp,v 1.2 2013/05/06 14:46:58 joerg Exp $

--- engine/metadata.hpp.orig	2013-01-26 03:01:41.000000000 +0000
+++ engine/metadata.hpp
@@ -38,13 +38,19 @@
 #include <set>
 #include <string>
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "utils/noncopyable.hpp"
 
 namespace utils {
 namespace config { class tree; }
-namespace datetime { class delta; }
+namespace datetime { struct delta; }
 namespace fs { class path; }
 namespace units { class bytes; }
 }  // namespace utils
@@ -73,7 +79,7 @@ class metadata {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
     friend class metadata_builder;
 
