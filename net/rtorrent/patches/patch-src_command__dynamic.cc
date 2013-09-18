$NetBSD: patch-src_command__dynamic.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/command_dynamic.cc.orig	2012-03-20 16:25:05.000000000 +0000
+++ src/command_dynamic.cc
@@ -43,6 +43,16 @@
 #include "command_helpers.h"
 #include "rpc/parse.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+#define STD_BIND std::bind
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+#define STD_BIND std::tr1::bind
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 std::string
 system_method_generate_command(torrent::Object::list_const_iterator first, torrent::Object::list_const_iterator last) {
   std::string command;
@@ -157,15 +167,15 @@ system_method_insert_object(const torren
 
     rpc::commands.insert_slot<rpc::command_base_is_type<rpc::command_base_call<rpc::target_type> >::type>
       (create_new_key(rawKey),
-       tr1::bind(&rpc::object_storage::call_function_str, control->object_storage(),
-                 rawKey, tr1::placeholders::_1, tr1::placeholders::_2),
+       STD_BIND(&rpc::object_storage::call_function_str, control->object_storage(),
+                 rawKey, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2),
        &rpc::command_base_call<rpc::target_type>,
        cmd_flags, NULL, NULL);
 
   } else {
     rpc::commands.insert_slot<rpc::command_base_is_type<rpc::command_base_call<rpc::target_type> >::type>
       (create_new_key(rawKey),
-       tr1::bind(&rpc::object_storage::get_str, control->object_storage(), rawKey),
+       STD_BIND(&rpc::object_storage::get_str, control->object_storage(), rawKey),
        &rpc::command_base_call<rpc::target_type>,
        cmd_flags, NULL, NULL);
   }
@@ -174,7 +184,7 @@ system_method_insert_object(const torren
   // if (flags & rpc::object_storage::flag_rlookup) {
   //   rpc::commands.insert_slot<rpc::command_base_is_type<rpc::command_base_call_string<rpc::target_type> >::type>
   //     (create_new_key<9>(rawKey, ".rlookup"),
-  //      tr1::bind(&rpc::object_storage::rlookup_obj_list, control->object_storage(), rawKey),
+  //      STD_BIND(&rpc::object_storage::rlookup_obj_list, control->object_storage(), rawKey),
   //      &rpc::command_base_call_string<rpc::target_type>,
   //      cmd_flags, NULL, NULL);
   // }
@@ -188,21 +198,21 @@ system_method_insert_object(const torren
     case rpc::object_storage::flag_bool_type:
       rpc::commands.insert_slot<rpc::command_base_is_type<rpc::command_base_call_value<rpc::target_type> >::type>
         (create_new_key<5>(rawKey, ".set"),
-         tr1::bind(&rpc::object_storage::set_str_bool, control->object_storage(), rawKey, tr1::placeholders::_2),
+         STD_BIND(&rpc::object_storage::set_str_bool, control->object_storage(), rawKey, STD_PLACEHOLDERS::_2),
          &rpc::command_base_call_value<rpc::target_type>,
          cmd_flags, NULL, NULL);
       break;
     case rpc::object_storage::flag_value_type:
       rpc::commands.insert_slot<rpc::command_base_is_type<rpc::command_base_call_value<rpc::target_type> >::type>
         (create_new_key<5>(rawKey, ".set"),
-         tr1::bind(&rpc::object_storage::set_str_value, control->object_storage(), rawKey, tr1::placeholders::_2),
+         STD_BIND(&rpc::object_storage::set_str_value, control->object_storage(), rawKey, STD_PLACEHOLDERS::_2),
          &rpc::command_base_call_value<rpc::target_type>,
          cmd_flags, NULL, NULL);
       break;
     case rpc::object_storage::flag_string_type:
       rpc::commands.insert_slot<rpc::command_base_is_type<rpc::command_base_call_string<rpc::target_type> >::type>
         (create_new_key<5>(rawKey, ".set"),
-         tr1::bind(&rpc::object_storage::set_str_string, control->object_storage(), rawKey, tr1::placeholders::_2),
+         STD_BIND(&rpc::object_storage::set_str_string, control->object_storage(), rawKey, STD_PLACEHOLDERS::_2),
          &rpc::command_base_call_string<rpc::target_type>,
          cmd_flags, NULL, NULL);
       break;
@@ -423,36 +433,36 @@ system_method_list_keys(const torrent::O
 }
 
 #define CMD2_METHOD_INSERT(key, flags) \
-  CMD2_ANY_LIST(key, tr1::bind(&system_method_insert_object, tr1::placeholders::_2, flags));
+  CMD2_ANY_LIST(key, STD_BIND(&system_method_insert_object, STD_PLACEHOLDERS::_2, flags));
 
 void
 initialize_command_dynamic() {
   CMD2_VAR_BOOL    ("method.use_deprecated", true);
   CMD2_VAR_VALUE   ("method.use_intermediate", 1);
 
-  CMD2_ANY_LIST    ("method.insert",             tr1::bind(&system_method_insert, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("method.insert.value",       tr1::bind(&system_method_insert_object, tr1::placeholders::_2, rpc::object_storage::flag_value_type));
+  CMD2_ANY_LIST    ("method.insert",             STD_BIND(&system_method_insert, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("method.insert.value",       STD_BIND(&system_method_insert_object, STD_PLACEHOLDERS::_2, (int)rpc::object_storage::flag_value_type));
 
-  CMD2_METHOD_INSERT("method.insert.simple",     rpc::object_storage::flag_function_type);
+  CMD2_METHOD_INSERT("method.insert.simple",     (int)rpc::object_storage::flag_function_type);
   CMD2_METHOD_INSERT("method.insert.c_simple",   rpc::object_storage::flag_constant | rpc::object_storage::flag_function_type);
   CMD2_METHOD_INSERT("method.insert.s_c_simple", rpc::object_storage::flag_static |
                      rpc::object_storage::flag_constant |rpc::object_storage::flag_function_type);
 
-  CMD2_ANY_STRING  ("method.erase",     tr1::bind(&system_method_erase, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("method.redirect",  tr1::bind(&system_method_redirect, tr1::placeholders::_2));
-  CMD2_ANY_STRING  ("method.get",       tr1::bind(&rpc::object_storage::get_str, control->object_storage(),
-                                                       tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("method.set",       tr1::bind(&system_method_set_function, tr1::placeholders::_2));
-
-  CMD2_ANY_STRING  ("method.const",        tr1::bind(&rpc::object_storage::has_flag_str, control->object_storage(),
-                                                      tr1::placeholders::_2, rpc::object_storage::flag_constant));
-  CMD2_ANY_STRING_V("method.const.enable", tr1::bind(&rpc::object_storage::enable_flag_str, control->object_storage(),
-                                                     tr1::placeholders::_2, rpc::object_storage::flag_constant));
-
-  CMD2_ANY_LIST    ("method.has_key",   tr1::bind(&system_method_has_key, tr1::placeholders::_2));
-  CMD2_ANY_LIST    ("method.set_key",   tr1::bind(&system_method_set_key, tr1::placeholders::_2));
-  CMD2_ANY_STRING  ("method.list_keys", tr1::bind(&system_method_list_keys, tr1::placeholders::_2));
+  CMD2_ANY_STRING  ("method.erase",     STD_BIND(&system_method_erase, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("method.redirect",  STD_BIND(&system_method_redirect, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING  ("method.get",       STD_BIND(&rpc::object_storage::get_str, control->object_storage(),
+                                                       STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("method.set",       STD_BIND(&system_method_set_function, STD_PLACEHOLDERS::_2));
+
+  CMD2_ANY_STRING  ("method.const",        STD_BIND(&rpc::object_storage::has_flag_str, control->object_storage(),
+                                                      STD_PLACEHOLDERS::_2, (int)rpc::object_storage::flag_constant));
+  CMD2_ANY_STRING_V("method.const.enable", STD_BIND(&rpc::object_storage::enable_flag_str, control->object_storage(),
+                                                     STD_PLACEHOLDERS::_2, (int)rpc::object_storage::flag_constant));
+
+  CMD2_ANY_LIST    ("method.has_key",   STD_BIND(&system_method_has_key, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_LIST    ("method.set_key",   STD_BIND(&system_method_set_key, STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING  ("method.list_keys", STD_BIND(&system_method_list_keys, STD_PLACEHOLDERS::_2));
 
-  CMD2_ANY_STRING  ("method.rlookup",       tr1::bind(&rpc::object_storage::rlookup_obj_list, control->object_storage(), tr1::placeholders::_2));
-  CMD2_ANY_STRING_V("method.rlookup.clear", tr1::bind(&rpc::object_storage::rlookup_clear, control->object_storage(), tr1::placeholders::_2));
+  CMD2_ANY_STRING  ("method.rlookup",       STD_BIND(&rpc::object_storage::rlookup_obj_list, control->object_storage(), STD_PLACEHOLDERS::_2));
+  CMD2_ANY_STRING_V("method.rlookup.clear", STD_BIND(&rpc::object_storage::rlookup_clear, control->object_storage(), STD_PLACEHOLDERS::_2));
 }
