$NetBSD: patch-texk_web2c_luatexdir_lua_llualib.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/llualib.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/llualib.c	2023/05/02 15:26:43	66984
@@ -319,8 +319,8 @@ static int set_luaname(lua_State * L)
 {
     int k;
     const char *s;
-    if (lua_gettop(L) == 3) {
-        k = (int) luaL_checkinteger(L, 2);
+    if (lua_gettop(L) == 2) {
+        k = (int) luaL_checkinteger(L, 1);
         if (k > 65535 || k < 0) {
             /* error */
         } else {
@@ -328,8 +328,8 @@ static int set_luaname(lua_State * L)
                 free(luanames[k]);
                 luanames[k] = NULL;
             }
-            if (lua_type(L,3) == LUA_TSTRING) {
-                s = lua_tostring(L, 3);
+            if (lua_type(L, 2) == LUA_TSTRING) {
+                s = lua_tostring(L, 2);
                 if (s != NULL)
                     luanames[k] = xstrdup(s);
             }
@@ -340,7 +340,7 @@ static int set_luaname(lua_State * L)
 
 static int get_luaname(lua_State * L)
 {
-    int k = (int) luaL_checkinteger(L, 2);
+    int k = (int) luaL_checkinteger(L, 1);
     if (k > 65535 || k < 0) {
         /* error */
         lua_pushnil(L);
