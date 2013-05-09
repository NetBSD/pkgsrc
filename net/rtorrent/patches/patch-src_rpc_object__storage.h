$NetBSD: patch-src_rpc_object__storage.h,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/rpc/object_storage.h.orig	2013-05-03 22:41:30.000000000 +0000
+++ src/rpc/object_storage.h
@@ -42,7 +42,13 @@
 #define RTORRENT_RPC_OBJECT_STORAGE_H
 
 #include <cstring>
+#if __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
+using std::tr1::unordered_map;
+#endif
 #include <torrent/object.h>
 
 #include "rak/unordered_vector.h"
@@ -56,7 +62,7 @@ struct object_storage_node {
   char            flags;
 };
 
-typedef std::tr1::unordered_map<fixed_key_type<64>, object_storage_node, hash_fixed_key_type> object_storage_base_type;
+typedef unordered_map<fixed_key_type<64>, object_storage_node, hash_fixed_key_type> object_storage_base_type;
 
 class object_storage : private object_storage_base_type {
 public:
@@ -89,21 +95,23 @@ public:
   using base_type::clear;
   using base_type::find;
   using base_type::erase;
-  
-  static const unsigned int flag_generic_type  = 0x1;
-  static const unsigned int flag_bool_type     = 0x2;
-  static const unsigned int flag_value_type    = 0x3;
-  static const unsigned int flag_string_type   = 0x4;
-  static const unsigned int flag_list_type     = 0x5;
-  static const unsigned int flag_function_type = 0x6;
-  static const unsigned int flag_multi_type    = 0x7;
-
-  static const unsigned int mask_type          = 0xf;
-
-  static const unsigned int flag_constant      = 0x10;
-  static const unsigned int flag_static        = 0x20;
-  static const unsigned int flag_private       = 0x40;
-  static const unsigned int flag_rlookup       = 0x80;
+
+  enum {
+    flag_generic_type  = 0x1,
+    flag_bool_type     = 0x2,
+    flag_value_type    = 0x3,
+    flag_string_type   = 0x4,
+    flag_list_type     = 0x5,
+    flag_function_type = 0x6,
+    flag_multi_type    = 0x7,
+
+    mask_type          = 0xf,
+
+    flag_constant      = 0x10,
+    flag_static        = 0x20,
+    flag_private       = 0x40,
+    flag_rlookup       = 0x80
+  };
 
   static const size_t key_size = key_type::max_size;
 
