$NetBSD: patch-engine_context.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- engine/context.hpp.orig	2013-05-06 08:09:15.000000000 +0000
+++ engine/context.hpp
@@ -35,7 +35,13 @@
 #include <map>
 #include <ostream>
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "utils/fs/path.hpp"
 
@@ -51,7 +57,7 @@ class context {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
 public:
     context(const utils::fs::path&,
