$NetBSD: patch-src_luacheck_stages.lua,v 1.1 2026/11/27 07:40:49 wiz Exp $

Fix for lua 5.4.
https://github.com/lunarmodules/luacheck/commit/36decdeb0ce80f00737a4de815711cdf70959080

--- src/luacheck/stages.lua.orig	2026-11-27 07:35:58.099126283 +0000
+++ src/luacheck/stages.lua
@@ -31,7 +31,7 @@ for _, name in ipairs(stages.names) do
 stages.modules = {}
 
 for _, name in ipairs(stages.names) do
-   table.insert(stages.modules, require("luacheck.stages." .. name))
+   table.insert(stages.modules, (require("luacheck.stages." .. name)))
 end
 
 stages.warnings = {}
