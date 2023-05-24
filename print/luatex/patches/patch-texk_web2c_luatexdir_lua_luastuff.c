$NetBSD: patch-texk_web2c_luatexdir_lua_luastuff.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/luastuff.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/luastuff.c	2023/05/02 15:26:43	66984
@@ -323,7 +323,8 @@ void luainterpreter(void)
     /*tex
         The socket and mime libraries are a bit tricky to open because they use a
         load-time dependency that has to be worked around for luatex, where the C
-        module is loaded way before the lua module.
+        module is loaded way before the lua module. 
+        The mime library is always available, even if the socket library is not enabled.
     */
     if (!nosocket_option) {
         /* todo: move this to common */
@@ -348,6 +349,23 @@ void luainterpreter(void)
         lua_pop(L, 2);
         /*tex preload the pure \LUA\ modules */
         luatex_socketlua_open(L);
+    } else {
+        lua_getglobal(L, "package");
+        lua_getfield(L, -1, "loaded");
+        if (!lua_istable(L, -1)) {
+            lua_newtable(L);
+            lua_setfield(L, -2, "loaded");
+            lua_getfield(L, -1, "loaded");
+        }
+        /*tex |package.loaded.mime = nil| */
+        luaopen_mime_core(L);
+        lua_setfield(L, -2, "mime.core");
+        lua_pushnil(L);
+        lua_setfield(L, -2, "mime");
+        /*tex pop the table */
+        lua_pop(L, 1);
+        /*tex preload the pure \LUA\ mime module */
+        luatex_socketlua_safe_open(L);
     }
     luaopen_zlib(L);
     luaopen_gzip(L);
