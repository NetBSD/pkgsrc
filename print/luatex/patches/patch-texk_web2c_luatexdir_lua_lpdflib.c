$NetBSD: patch-texk_web2c_luatexdir_lua_lpdflib.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/lpdflib.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/lpdflib.c	2023/05/02 15:26:43	66984
@@ -1048,7 +1048,7 @@ static int setpdforigin(lua_State * L)
     if (lua_type(L, 1) == LUA_TNUMBER) {
         h = (int) lua_roundnumber(L, 1);
         if (lua_type(L, 2) == LUA_TNUMBER) {
-            v = (int) lua_roundnumber(L, 1);
+            v = (int) lua_roundnumber(L, 2);
         } else {
             v = h;
         }
