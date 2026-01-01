$NetBSD: patch-runtime_lua_vim_treesitter_languagetree.lua,v 1.2 2026/01/01 16:30:47 leot Exp $

Fix build with tree-sitter 0.26.
https://github.com/subnut/cports/blob/neovim-wasm/main/neovim/patches/backport-33141.patch

--- runtime/lua/vim/treesitter/languagetree.lua.orig	2026-01-01 16:19:26.136691938 +0000
+++ runtime/lua/vim/treesitter/languagetree.lua
@@ -43,8 +43,10 @@
 local query = require('vim.treesitter.query')
 local language = require('vim.treesitter.language')
 local Range = require('vim.treesitter._range')
+local hrtime = vim.uv.hrtime
 
-local default_parse_timeout_ms = 3
+-- Parse in 3ms chunks.
+local default_parse_timeout_ns = 3 * 1000000
 
 ---@type Range2
 local entire_document_range = { 0, math.huge }
@@ -198,16 +200,16 @@ function LanguageTree:_set_logger()
   self._parser:_set_logger(log_lex, log_parse, self._logger)
 end
 
----Measure execution time of a function
+---Measure execution time of a function, in nanoseconds.
 ---@generic R1, R2, R3
 ---@param f fun(): R1, R2, R3
 ---@return number, R1, R2, R3
 local function tcall(f, ...)
-  local start = vim.uv.hrtime()
+  local start = hrtime()
   ---@diagnostic disable-next-line
   local r = { f(...) }
   --- @type number
-  local duration = (vim.uv.hrtime() - start) / 1000000
+  local duration = hrtime() - start
   --- @diagnostic disable-next-line: redundant-return-value
   return duration, unpack(r)
 end
@@ -388,18 +390,29 @@ function LanguageTree:_parse_regions(ran
       )
     then
       self._parser:set_included_ranges(ranges)
-      self._parser:set_timeout(thread_state.timeout and thread_state.timeout * 1000 or 0) -- ms -> micros
 
-      local parse_time, tree, tree_changes =
-        tcall(self._parser.parse, self._parser, self._trees[i], self._source, true)
+      local parse_time, tree, tree_changes = tcall(
+        self._parser.parse,
+        self._parser,
+        self._trees[i],
+        self._source,
+        true,
+        thread_state.timeout
+      )
       while true do
         if tree then
           break
         end
         coroutine.yield(self._trees, false)
 
-        parse_time, tree, tree_changes =
-          tcall(self._parser.parse, self._parser, self._trees[i], self._source, true)
+        parse_time, tree, tree_changes = tcall(
+          self._parser.parse,
+          self._parser,
+          self._trees[i],
+          self._source,
+          true,
+          thread_state.timeout
+        )
       end
 
       self:_subtract_time(thread_state, parse_time)
@@ -503,7 +516,7 @@ function LanguageTree:_async_parse(range
   local buf = is_buffer_parser and vim.b[source] or nil
   local ct = is_buffer_parser and buf.changedtick or nil
   local total_parse_time = 0
-  local redrawtime = vim.o.redrawtime
+  local redrawtime = vim.o.redrawtime * 1000000
 
   local thread_state = {} ---@type ParserThreadState
 
@@ -997,7 +1010,7 @@ function LanguageTree:_get_injections(ra
 
   ---@type table<integer,vim.treesitter.languagetree.Injection>
   local injections = {}
-  local start = vim.uv.hrtime()
+  local start = hrtime()
 
   local full_scan = range == true or self._injection_query.has_combined_injections
 
@@ -1021,9 +1034,9 @@ function LanguageTree:_get_injections(ra
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
 
