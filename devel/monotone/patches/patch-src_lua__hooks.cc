$NetBSD: patch-src_lua__hooks.cc,v 1.1 2021/03/06 08:57:54 nia Exp $

The LUA_QL macro was removed in lua 5.4.0.  Make the same transformation
as was made in the lua code itself.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/743f0c8ae3af8551c1047c049e9ad2d54abc7af9/f/monotone-1.1-lua-ql.patch

--- src/lua_hooks.cc.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/lua_hooks.cc
@@ -90,7 +90,7 @@ extern "C"
         s = lua_tostring(LS, -1);
         if (s == NULL)
           return luaL_error(
-            LS, LUA_QL("tostring") " must return a string to ", LUA_QL("print")
+            LS, "'tostring' must return a string to 'print'"
           );
 
         if (i > 1)
