$NetBSD: patch-runtime_lua_vim_treesitter_languagetree.lua,v 1.1 2025/12/23 00:07:16 wiz Exp $

Fix build with tree-sitter 0.26.
https://github.com/subnut/cports/blob/neovim-wasm/main/neovim/patches/backport-33141.patch

--- runtime/lua/vim/treesitter/languagetree.lua.orig	2025-12-23 00:02:36.443793560 +0000
+++ runtime/lua/vim/treesitter/languagetree.lua
@@ -1010,7 +1010,7 @@ function LanguageTree:_get_injections(ra
 
   ---@type table<integer,vim.treesitter.languagetree.Injection>
   local injections = {}
-  local start = vim.uv.hrtime()
+  local start = hrtime()
 
   local full_scan = range == true or self._injection_query.has_combined_injections
 
@@ -1034,9 +1034,9 @@ function LanguageTree:_get_injections(ra
       end
 
       -- Check the current function duration against the timeout, if it exists.
-      local current_time = vim.uv.hrtime()
-      self:_subtract_time(thread_state, (current_time - start) / 1000000)
-      start = current_time
+      local current_time = hrtime()
+      self:_subtract_time(thread_state, current_time - start)
+      start = hrtime()
     end
   end
 
