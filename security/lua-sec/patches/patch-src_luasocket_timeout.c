$NetBSD: patch-src_luasocket_timeout.c,v 1.1 2020/08/07 02:05:07 joerg Exp $

--- src/luasocket/timeout.c.orig	2020-08-07 02:01:45.609031005 +0000
+++ src/luasocket/timeout.c
@@ -143,7 +143,7 @@ double timeout_gettime(void) {
 * Initializes module
 \*-------------------------------------------------------------------------*/
 int timeout_open(lua_State *L) {
-#if LUA_VERSION_NUM > 501 && !defined(LUA_COMPAT_MODULE)
+#if LUA_VERSION_NUM > 501
     luaL_setfuncs(L, func, 0);
 #else
     luaL_openlib(L, NULL, func, 0);
