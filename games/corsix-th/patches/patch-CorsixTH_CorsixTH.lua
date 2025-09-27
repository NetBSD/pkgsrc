$NetBSD: patch-CorsixTH_CorsixTH.lua,v 1.1 2025/09/27 09:16:12 triaxx Exp $

Explicitly add search path for .dylib library because only .lua and .so files
are searched.

--- CorsixTH/CorsixTH.lua.orig	2025-08-08 19:15:08.000000000 +0000
+++ CorsixTH/CorsixTH.lua
@@ -20,7 +20,7 @@ end
 local pathsep = package.config:sub(1, 1)
 local base_dir = debug.getinfo(1, "S").source:sub(2, -13)
 local code_dir = base_dir .. "Lua" .. pathsep
-package.cpath = base_dir .. '?.so;' .. package.cpath
+package.cpath = base_dir .. '?.so;' .. '@PKGSRC_LUA_CPATH@/?.dylib;' .. package.cpath
 for _, arg in ipairs{...} do
   local dir = arg:match"^%-%-lua%-dir=(.*)$"
   if dir then
