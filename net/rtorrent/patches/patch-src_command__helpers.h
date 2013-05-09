$NetBSD: patch-src_command__helpers.h,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/command_helpers.h.orig	2013-05-03 22:59:40.000000000 +0000
+++ src/command_helpers.h
@@ -41,8 +41,6 @@
 #include "rpc/parse_commands.h"
 #include "rpc/object_storage.h"
 
-namespace tr1 { using namespace std::tr1; }
-
 void initialize_commands();
 
 //
@@ -100,43 +98,43 @@ void initialize_commands();
 
 #define CMD2_VAR_BOOL(key, value)                                       \
   control->object_storage()->insert_c_str(key, int64_t(value), rpc::object_storage::flag_bool_type); \
-  CMD2_ANY(key, tr1::bind(&rpc::object_storage::get, control->object_storage(), \
+  CMD2_ANY(key, bind(&rpc::object_storage::get, control->object_storage(), \
                                torrent::raw_string::from_c_str(key)));  \
-  CMD2_ANY_VALUE(key ".set", tr1::bind(&rpc::object_storage::set_bool, control->object_storage(), \
-                                            torrent::raw_string::from_c_str(key), tr1::placeholders::_2));
+  CMD2_ANY_VALUE(key ".set", bind(&rpc::object_storage::set_bool, control->object_storage(), \
+                                            torrent::raw_string::from_c_str(key), STD_PLACEHOLDERS::_2));
 
 #define CMD2_VAR_VALUE(key, value)                                      \
   control->object_storage()->insert_c_str(key, int64_t(value), rpc::object_storage::flag_value_type); \
-  CMD2_ANY(key, tr1::bind(&rpc::object_storage::get, control->object_storage(), \
+  CMD2_ANY(key, bind(&rpc::object_storage::get, control->object_storage(), \
                                torrent::raw_string::from_c_str(key)));  \
-  CMD2_ANY_VALUE(key ".set", tr1::bind(&rpc::object_storage::set_value, control->object_storage(), \
-                                            torrent::raw_string::from_c_str(key), tr1::placeholders::_2));
+  CMD2_ANY_VALUE(key ".set", bind(&rpc::object_storage::set_value, control->object_storage(), \
+                                            torrent::raw_string::from_c_str(key), STD_PLACEHOLDERS::_2));
 
 #define CMD2_VAR_STRING(key, value)                                     \
   control->object_storage()->insert_c_str(key, value, rpc::object_storage::flag_string_type); \
-  CMD2_ANY(key, tr1::bind(&rpc::object_storage::get, control->object_storage(), \
+  CMD2_ANY(key, bind(&rpc::object_storage::get, control->object_storage(), \
                                torrent::raw_string::from_c_str(key)));  \
-  CMD2_ANY_STRING(key ".set", tr1::bind(&rpc::object_storage::set_string, control->object_storage(), \
-                                             torrent::raw_string::from_c_str(key), tr1::placeholders::_2));
+  CMD2_ANY_STRING(key ".set", bind(&rpc::object_storage::set_string, control->object_storage(), \
+                                             torrent::raw_string::from_c_str(key), STD_PLACEHOLDERS::_2));
 
 
 #define CMD2_VAR_C_STRING(key, value)                                   \
   control->object_storage()->insert_c_str(key, value, rpc::object_storage::flag_string_type); \
-  CMD2_ANY(key, tr1::bind(&rpc::object_storage::get, control->object_storage(), \
+  CMD2_ANY(key, bind(&rpc::object_storage::get, control->object_storage(), \
                                torrent::raw_string::from_c_str(key)));
 
 #define CMD2_VAR_LIST(key)                                              \
   control->object_storage()->insert_c_str(key, torrent::Object::create_list(), rpc::object_storage::flag_list_type); \
-  CMD2_ANY(key, tr1::bind(&rpc::object_storage::get, control->object_storage(), \
+  CMD2_ANY(key, bind(&rpc::object_storage::get, control->object_storage(), \
                                torrent::raw_string::from_c_str(key)));  \
-  CMD2_ANY_LIST(key ".set", tr1::bind(&rpc::object_storage::set_list, control->object_storage(), \
-                                           torrent::raw_string::from_c_str(key), tr1::placeholders::_2)); \
-  CMD2_ANY_VOID(key ".push_back", tr1::bind(&rpc::object_storage::list_push_back, control->object_storage(), \
-                                                 torrent::raw_string::from_c_str(key), tr1::placeholders::_2));
+  CMD2_ANY_LIST(key ".set", bind(&rpc::object_storage::set_list, control->object_storage(), \
+                                           torrent::raw_string::from_c_str(key), STD_PLACEHOLDERS::_2)); \
+  CMD2_ANY_VOID(key ".push_back", bind(&rpc::object_storage::list_push_back, control->object_storage(), \
+                                                 torrent::raw_string::from_c_str(key), STD_PLACEHOLDERS::_2));
 
 #define CMD2_FUNC_SINGLE(key, cmds)                                     \
-  CMD2_ANY(key, tr1::bind(&rpc::command_function_call, torrent::raw_string::from_c_str(cmds), \
-                               tr1::placeholders::_1, tr1::placeholders::_2));
+  CMD2_ANY(key, bind(&rpc::command_function_call, torrent::raw_string::from_c_str(cmds), \
+                               STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
 
 #define CMD2_REDIRECT(from_key, to_key) \
   rpc::commands.create_redirect(from_key, to_key, rpc::CommandMap::flag_public_xmlrpc | rpc::CommandMap::flag_dont_delete);
