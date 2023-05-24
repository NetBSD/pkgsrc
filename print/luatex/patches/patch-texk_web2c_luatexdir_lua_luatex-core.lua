$NetBSD: patch-texk_web2c_luatexdir_lua_luatex-core.lua,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/luatex-core.lua	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/luatex-core.lua	2023/05/02 15:26:43	66984
@@ -7,7 +7,7 @@
 --     copyright = 'LuaTeX Development Team',
 -- }
 
-LUATEXCOREVERSION = 1.151 -- we reflect the luatex version where changes happened
+LUATEXCOREVERSION = 1.161 -- we reflect the luatex version where changes happened
 
 -- This file overloads some Lua functions. The readline variants provide the same
 -- functionality as LuaTeX <= 1.04 and doing it this way permits us to keep the
@@ -16,6 +16,8 @@ LUATEXCOREVERSION = 1.151 -- we reflect
 -- We test for functions already being defined so that we don't overload ones that
 -- are provided in the startup script.
 
+
+
 local saferoption = status.safer_option
 local shellescape = status.shell_escape -- 0 (disabled) 1 (anything) 2 (restricted)
 local kpseused    = status.kpse_used    -- 0 1
@@ -34,7 +36,7 @@ if kpseused == 1 then
     local kpse_recordoutputfile = kpse.record_output_file
 
     local io_open               = io.open
-    local io_popen              = io.popen
+    -- local io_popen              = io.popen -- not need, we  use os.kpsepopen
     local io_lines              = io.lines
 
     local fio_readline          = fio.readline
@@ -75,12 +77,13 @@ if kpseused == 1 then
         return f
     end
 
-    local function luatex_io_popen(name,...)
-        local okay, found = kpse_checkpermission(name)
-        if okay and found then
-            return io_popen(found,...)
-        end
-    end
+    --  not need, we  use os.kpsepopen 
+    --local function luatex_io_popen(name,...)
+    --    local okay, found = kpse_checkpermission(name)
+    --    if okay and found then
+    --        return io_popen(found,...)
+    --    end
+    --end
 
     -- local function luatex_io_lines(name,how)
     --     if name then
@@ -130,7 +133,8 @@ if kpseused == 1 then
     mt.lines = luatex_io_readline
 
     io.open  = luatex_io_open
-    io.popen = luatex_io_popen
+    --io.popen = luatex_io_popen -- not need, we  use os.kpsepopen
+    io.popen = os.kpsepopen
 
 else
 
@@ -169,6 +173,8 @@ if saferoption == 1 then
     os.setenv  = installdummy("os.setenv")
     os.tempdir = installdummy("os.tempdir")
 
+    os.kpsepopen = installdummy("os.kpsepopen")
+
     io.popen   = installdummy("io.popen")
     io.open    = installdummy("io.open",luatex_io_open_readonly)
 
