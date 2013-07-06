$NetBSD: patch-Lib_lua_luaruntime.swg,v 1.1 2013/07/06 23:11:51 wiz Exp $

Fix for lua-5.2.

--- Lib/lua/luaruntime.swg.orig	2008-03-17 08:50:59.000000000 +0000
+++ Lib/lua/luaruntime.swg
@@ -28,7 +28,11 @@ SWIGEXPORT int SWIG_init(lua_State* L)
 {
   int i;
   /* start with global table */
+#ifdef LUA_RIDX_GLOBALS
+  lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS);
+#else
   lua_pushvalue(L,LUA_GLOBALSINDEX);
+#endif
   /* SWIG's internal initalisation */
   SWIG_InitializeModule((void*)L);
   SWIG_PropagateClientData();
