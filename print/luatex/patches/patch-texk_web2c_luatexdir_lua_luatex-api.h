$NetBSD: patch-texk_web2c_luatexdir_lua_luatex-api.h,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/luatex-api.h	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/luatex-api.h	2023/05/02 15:26:43	66984
@@ -123,6 +123,7 @@ extern int luaopen_profiler(lua_State *
 extern int luaopen_socket_core(lua_State * L);
 extern int luaopen_mime_core(lua_State * L);
 extern void luatex_socketlua_open(lua_State * L);
+extern void luatex_socketlua_safe_open(lua_State * L);
 
 extern int luaopen_img(lua_State * L);
 extern int l_new_image(lua_State * L);
