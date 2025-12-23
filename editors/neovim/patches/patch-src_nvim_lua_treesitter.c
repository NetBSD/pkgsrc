$NetBSD: patch-src_nvim_lua_treesitter.c,v 1.1 2025/12/23 00:07:16 wiz Exp $

Fix build with tree-sitter 0.26.
https://github.com/subnut/cports/blob/neovim-wasm/main/neovim/patches/backport-33141.patch

--- src/nvim/lua/treesitter.c.orig	2025-11-02 16:14:24.000000000 +0000
+++ src/nvim/lua/treesitter.c
@@ -15,6 +15,8 @@
 #include <tree_sitter/api.h>
 #include <uv.h>
 
+#include "nvim/os/time.h"
+
 #ifdef HAVE_WASMTIME
 # include <wasm.h>
 
@@ -53,6 +55,11 @@ typedef struct {
   const TSTree *tree;
 } TSLuaTree;
 
+typedef struct {
+  uint64_t parse_start_time;
+  uint64_t timeout_threshold_ns;
+} TSLuaParserCallbackPayload;
+
 #ifdef INCLUDE_GENERATED_DECLARATIONS
 # include "lua/treesitter.c.generated.h"
 #endif
@@ -363,8 +370,6 @@ static struct luaL_Reg parser_meta[] = {
   { "reset", parser_reset },
   { "set_included_ranges", parser_set_ranges },
   { "included_ranges", parser_get_ranges },
-  { "set_timeout", parser_set_timeout },
-  { "timeout", parser_get_timeout },
   { "_set_logger", parser_set_logger },
   { "_logger", parser_get_logger },
   { NULL, NULL }
@@ -488,6 +493,13 @@ static void push_ranges(lua_State *L, co
   }
 }
 
+static bool on_parser_progress(TSParseState *state)
+{
+  TSLuaParserCallbackPayload *payload = state->payload;
+  uint64_t parse_time = os_hrtime() - payload->parse_start_time;
+  return parse_time >= payload->timeout_threshold_ns;
+}
+
 static int parser_parse(lua_State *L)
 {
   TSParser *p = parser_check(L, 1);
@@ -525,7 +537,17 @@ static int parser_parse(lua_State *L)
     }
 
     input = (TSInput){ (void *)buf, input_cb, TSInputEncodingUTF8, NULL };
-    new_tree = ts_parser_parse(p, old_tree, input);
+    if (!lua_isnil(L, 5)) {
+      uint64_t timeout_ns = (uint64_t)lua_tointeger(L, 5);
+      TSLuaParserCallbackPayload payload =
+        (TSLuaParserCallbackPayload){ .parse_start_time = os_hrtime(),
+                                      .timeout_threshold_ns = timeout_ns };
+      TSParseOptions parse_options = { .payload = &payload,
+                                       .progress_callback = on_parser_progress };
+      new_tree = ts_parser_parse_with_options(p, old_tree, input, parse_options);
+    } else {
+      new_tree = ts_parser_parse(p, old_tree, input);
+    }
 
     break;
 
@@ -535,12 +557,11 @@ static int parser_parse(lua_State *L)
 
   bool include_bytes = (lua_gettop(L) >= 4) && lua_toboolean(L, 4);
 
-  // Sometimes parsing fails (timeout, or wrong parser ABI)
-  // In those case, just return an error.
   if (!new_tree) {
-    if (ts_parser_timeout_micros(p) == 0) {
-      // No timeout set, must have had an error
-      return luaL_error(L, "An error occurred when parsing.");
+    // Sometimes parsing fails (no language was set, or it was set to one with an incompatible ABI)
+    // In those cases, just return an error.
+    if (!ts_parser_language(p)) {
+      return luaL_error(L, "Language was unset, or has an incompatible ABI.");
     }
     return 0;
   }
@@ -671,26 +692,6 @@ static int parser_get_ranges(lua_State *
   return 1;
 }
 
-static int parser_set_timeout(lua_State *L)
-{
-  TSParser *p = parser_check(L, 1);
-
-  if (lua_gettop(L) < 2) {
-    luaL_error(L, "integer expected");
-  }
-
-  uint32_t timeout = (uint32_t)luaL_checkinteger(L, 2);
-  ts_parser_set_timeout_micros(p, timeout);
-  return 0;
-}
-
-static int parser_get_timeout(lua_State *L)
-{
-  TSParser *p = parser_check(L, 1);
-  lua_pushinteger(L, (lua_Integer)ts_parser_timeout_micros(p));
-  return 1;
-}
-
 static void logger_cb(void *payload, TSLogType logtype, const char *s)
 {
   TSLuaLoggerOpts *opts = (TSLuaLoggerOpts *)payload;
