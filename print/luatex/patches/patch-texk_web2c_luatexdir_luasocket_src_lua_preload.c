$NetBSD: patch-texk_web2c_luatexdir_luasocket_src_lua_preload.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -1.17.0

--- texk/web2c/luatexdir/luasocket/src/lua_preload.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/luasocket/src/lua_preload.c	2023/05/02 15:26:43	66984
@@ -16,6 +16,7 @@ int luatex_ftp_lua_open(lua_State*);
 
 
 extern void luatex_socketlua_open (lua_State *) ;
+extern void luatex_socketlua_safe_open (lua_State *) ;
 #include "ftp_lua.c"
 #include "headers_lua.c" 
 #include "http_lua.c"
@@ -47,3 +48,11 @@ luatex_socketlua_open (lua_State *L) {
     TEST(luatex_http_lua_open(L));
     TEST(luatex_ftp_lua_open(L));
 }
+
+/* luatex_socketlua_safe_open: load safe modules */
+/* of luasocket ( mime ).                        */
+void
+luatex_socketlua_safe_open (lua_State *L) {
+    TEST(luatex_ltn12_lua_open(L));
+    TEST(luatex_mime_lua_open(L));
+}
