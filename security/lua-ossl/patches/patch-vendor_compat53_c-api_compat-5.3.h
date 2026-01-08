$NetBSD: patch-vendor_compat53_c-api_compat-5.3.h,v 1.1 2026/01/08 22:50:47 alnsn Exp $

PR#221: Support Lua 5.5
https://github.com/wahern/luaossl/pull/221

--- vendor/compat53/c-api/compat-5.3.h.orig	2022-07-11 05:40:14.000000000 +0000
+++ vendor/compat53/c-api/compat-5.3.h
@@ -399,11 +399,11 @@ COMPAT53_API void luaL_requiref (lua_Sta
 
 
 /* other Lua versions */
-#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 501 || LUA_VERSION_NUM > 504
+#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 501 || LUA_VERSION_NUM > 505
 
-#  error "unsupported Lua version (i.e. not Lua 5.1, 5.2, 5.3, or 5.4)"
+#  error "unsupported Lua version (i.e. not Lua 5.1, 5.2, 5.3, 5.4, or 5.5)"
 
-#endif /* other Lua versions except 5.1, 5.2, 5.3, and 5.4 */
+#endif /* other Lua versions except 5.1, 5.2, 5.3, 5.4, and 5.5 */
 
 
 
