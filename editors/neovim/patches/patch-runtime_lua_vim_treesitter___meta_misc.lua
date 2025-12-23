$NetBSD: patch-runtime_lua_vim_treesitter___meta_misc.lua,v 1.1 2025/12/23 00:07:15 wiz Exp $

Fix build with tree-sitter 0.26.
https://github.com/subnut/cports/blob/neovim-wasm/main/neovim/patches/backport-33141.patch

--- runtime/lua/vim/treesitter/_meta/misc.lua.orig	2025-11-02 16:14:24.000000000 +0000
+++ runtime/lua/vim/treesitter/_meta/misc.lua
@@ -5,12 +5,10 @@ error('Cannot require a meta file')
 ---@alias TSLoggerCallback fun(logtype: 'parse'|'lex', msg: string)
 
 ---@class TSParser: userdata
----@field parse fun(self: TSParser, tree: TSTree?, source: integer|string, include_bytes: boolean): TSTree, (Range4|Range6)[]
+---@field parse fun(self: TSParser, tree: TSTree?, source: integer|string, include_bytes: boolean, timeout_ns: integer?): TSTree?, (Range4|Range6)[]
 ---@field reset fun(self: TSParser)
 ---@field included_ranges fun(self: TSParser, include_bytes: boolean?): integer[]
 ---@field set_included_ranges fun(self: TSParser, ranges: (Range6|TSNode)[])
----@field set_timeout fun(self: TSParser, timeout: integer)
----@field timeout fun(self: TSParser): integer
 ---@field _set_logger fun(self: TSParser, lex: boolean, parse: boolean, cb: TSLoggerCallback)
 ---@field _logger fun(self: TSParser): TSLoggerCallback
 
