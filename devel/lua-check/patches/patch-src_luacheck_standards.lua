$NetBSD: patch-src_luacheck_standards.lua,v 1.1 2026/11/27 07:40:49 wiz Exp $

Fix for lua 5.5.
https://github.com/lunarmodules/luacheck/commit/eea104d82fa66f27df2a7d900b3c271a6ca122ac

--- src/luacheck/standards.lua.orig	2026-11-27 07:37:29.118850388 +0000
+++ src/luacheck/standards.lua
@@ -128,7 +128,8 @@ local function add_fields(def, fields, overwrite, igno
       return
    end
 
-   for field_name, field_def in pairs(fields) do
+   for fn, field_def in pairs(fields) do
+      local field_name = fn
       if type(field_name) == "string" or not ignore_array_part then
          if type(field_name) ~= "string" then
             field_name = field_def
