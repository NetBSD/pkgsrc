$NetBSD: patch-src_rpc_object__storage.cc,v 1.3 2013/09/18 16:33:09 joerg Exp $

--- src/rpc/object_storage.cc.orig	2013-08-31 16:44:50.000000000 +0000
+++ src/rpc/object_storage.cc
@@ -42,6 +42,16 @@
 #include "parse.h"
 #include "parse_commands.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+using std::placeholders::_1;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+using std::tr1::placeholders::_1;
+#endif
+
 namespace rpc {
 
 object_storage::local_iterator
@@ -246,7 +256,7 @@ object_storage::rlookup_list(const std::
   
   if (r_itr != m_rlookup.end())
     std::transform(r_itr->second.begin(), r_itr->second.end(), std::back_inserter(result),
-                   std::tr1::bind(&key_type::c_str, std::tr1::bind(rak::mem_ptr(&value_type::first), std::tr1::placeholders::_1)));
+                   bind(&key_type::c_str, bind(rak::mem_ptr(&value_type::first), _1)));
 
   return result;
 }
