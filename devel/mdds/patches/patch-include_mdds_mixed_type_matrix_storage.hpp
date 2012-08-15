$NetBSD: patch-include_mdds_mixed_type_matrix_storage.hpp,v 1.1 2012/08/15 18:13:38 wiz Exp $

Fix linking error with boost 1.50
http://code.google.com/p/multidimalgorithm/source/detail?r=09937e5d6b4b82efbff40da2aa50fb02f2250bb2

--- include/mdds/mixed_type_matrix_storage.hpp.orig	2012-07-19 03:09:49.000000000 +0000
+++ include/mdds/mixed_type_matrix_storage.hpp
@@ -32,6 +32,10 @@
 
 #include <boost/ptr_container/ptr_vector.hpp>
 #include <boost/ptr_container/ptr_map.hpp>
+// Boost.Pool indirectly pulls in Boost.System, causing linking error
+// with Boost 1.50, because some (deprecated) symbols from System are
+// not found.
+#define BOOST_SYSTEM_NO_DEPRECATED
 #include <boost/pool/object_pool.hpp>
 
 namespace mdds {
