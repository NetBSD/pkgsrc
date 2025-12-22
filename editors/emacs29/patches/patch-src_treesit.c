$NetBSD: patch-src_treesit.c,v 1.1 2025/12/22 19:51:06 tron Exp $

Fix build with version 0.26.x of "tree-sitter".

--- src/treesit.c.orig	2024-06-21 14:10:07.000000000 +0100
+++ src/treesit.c	2025-12-22 19:31:18.581988953 +0000
@@ -34,7 +34,7 @@
 # include "w32common.h"
 
 /* In alphabetical order.  */
-#undef ts_language_version
+#undef ts_language_abi_version
 #undef ts_node_child
 #undef ts_node_child_by_field_name
 #undef ts_node_child_count
@@ -89,7 +89,7 @@
 #undef ts_tree_get_changed_ranges
 #undef ts_tree_root_node
 
-DEF_DLL_FN (uint32_t, ts_language_version, (const TSLanguage *));
+DEF_DLL_FN (uint32_t, ts_language_abi_version, (const TSLanguage *));
 DEF_DLL_FN (TSNode, ts_node_child, (TSNode, uint32_t));
 DEF_DLL_FN (TSNode, ts_node_child_by_field_name,
 	    (TSNode, const char *, uint32_t));
@@ -166,7 +166,7 @@
   if (!library)
     return false;
 
-  LOAD_DLL_FN (library, ts_language_version);
+  LOAD_DLL_FN (library, ts_language_abi_version);
   LOAD_DLL_FN (library, ts_node_child);
   LOAD_DLL_FN (library, ts_node_child_by_field_name);
   LOAD_DLL_FN (library, ts_node_child_count);
@@ -224,7 +224,7 @@
   return true;
 }
 
-#define ts_language_version fn_ts_language_version
+#define ts_language_abi_version fn_ts_language_abi_version
 #define ts_node_child fn_ts_node_child
 #define ts_node_child_by_field_name fn_ts_node_child_by_field_name
 #define ts_node_child_count fn_ts_node_child_count
@@ -664,7 +664,7 @@
     {
       *signal_symbol = Qtreesit_load_language_error;
       *signal_data = list2 (Qversion_mismatch,
-			    make_fixnum (ts_language_version (lang)));
+			    make_fixnum (ts_language_abi_version (lang)));
       return NULL;
     }
   return lang;
@@ -735,7 +735,7 @@
 						       &signal_data);
       if (ts_language == NULL)
 	return Qnil;
-      uint32_t version =  ts_language_version (ts_language);
+      uint32_t version =  ts_language_abi_version (ts_language);
       return make_fixnum((ptrdiff_t) version);
     }
 }
