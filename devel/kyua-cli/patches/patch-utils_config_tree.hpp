$NetBSD: patch-utils_config_tree.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/config/tree.hpp.orig	2013-01-26 03:01:41.000000000 +0000
+++ utils/config/tree.hpp
@@ -34,7 +34,13 @@
 
 #include <map>
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include <lutok/state.hpp>
 
@@ -82,7 +88,7 @@ typedef std::map< std::string, std::stri
 /// deep_copy().
 class tree {
     /// The root of the tree.
-    std::tr1::shared_ptr< detail::static_inner_node > _root;
+    shared_ptr< detail::static_inner_node > _root;
 
     explicit tree(detail::static_inner_node*);
 
