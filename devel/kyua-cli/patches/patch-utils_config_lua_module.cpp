$NetBSD: patch-utils_config_lua_module.cpp,v 1.1 2013/06/15 00:31:34 jmmv Exp $

Support Lutok 0.3 (and therefore Lua 5.2).

This comes from upstream change df971a616a4cf930f00c836f837449d5a42589ec.

--- utils/config/lua_module.cpp
+++ utils/config/lua_module.cpp
@@ -42,7 +42,7 @@ namespace {
 
 /// Gets the tree singleton stored in the Lua state.
 ///
-/// \param state The Lua state.  The metadata of _G must contain a key named
+/// \param state The Lua state.  The registry must contain a key named
 ///    "tree" with a pointer to the singleton.
 ///
 /// \return A reference to the tree associated with the Lua state.
@@ -53,10 +53,15 @@ get_global_tree(lutok::state& state)
 {
     lutok::stack_cleaner cleaner(state);
 
-    if (!state.get_metafield(lutok::globals_index, "tree"))
+    state.push_value(lutok::registry_index);
+    state.push_string("tree");
+    state.get_table(-2);
+    if (state.is_nil())
         throw config::syntax_error("Cannot find tree singleton; global state "
                                    "corrupted?");
-    return **state.to_userdata< config::tree* >();
+    config::tree& tree = **state.to_userdata< config::tree* >();
+    state.pop(1);
+    return tree;
 }
 
 
@@ -254,7 +259,7 @@ config::redirect(lutok::state& state, tree& out_tree)
 {
     lutok::stack_cleaner cleaner(state);
 
-    state.new_table();
+    state.get_global_table();
     {
         state.push_string("__index");
         state.push_cxx_function(redirect_index);
@@ -263,11 +268,13 @@ config::redirect(lutok::state& state, tree& out_tree)
         state.push_string("__newindex");
         state.push_cxx_function(redirect_newindex);
         state.set_table(-3);
-
-        state.push_string("tree");
-        config::tree** tree = state.new_userdata< config::tree* >();
-        *tree = &out_tree;
-        state.set_table(-3);
     }
-    state.set_metatable(lutok::globals_index);
+    state.set_metatable(-1);
+
+    state.push_value(lutok::registry_index);
+    state.push_string("tree");
+    config::tree** tree = state.new_userdata< config::tree* >();
+    *tree = &out_tree;
+    state.set_table(-3);
+    state.pop(1);
 }
