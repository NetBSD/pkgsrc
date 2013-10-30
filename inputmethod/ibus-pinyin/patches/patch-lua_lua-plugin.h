$NetBSD: patch-lua_lua-plugin.h,v 1.1 2013/10/30 11:30:37 obache Exp $

* for Lua-5.1 and 5.2 API change

--- lua/lua-plugin.h.orig	2012-07-09 14:32:10.000000000 +0000
+++ lua/lua-plugin.h
@@ -29,6 +29,20 @@
 
 #include <glib-object.h>
 
+#ifdef LUA_VERSION_NUM
+# if (LUA_VERSION_NUM >= 501)
+#undef lua_open
+#define lua_open luaL_newstate
+# endif
+# if (LUA_VERSION_NUM >= 502)
+#undef lua_objlen
+#define lua_objlen lua_rawlen
+#undef luaL_register
+#define luaL_register(L,n,f) \
+	{ if ((n) == NULL) luaL_setfuncs(L,f,0); else luaL_newlib(L,f); }
+# endif
+#endif
+
 #define LUA_IMELIBNAME   "ime"
 LUALIB_API int (luaopen_ime) (lua_State * L);
 LUALIB_API int (luaopen_myos) (lua_State * L);
