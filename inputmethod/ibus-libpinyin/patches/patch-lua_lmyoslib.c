$NetBSD: patch-lua_lmyoslib.c,v 1.1 2014/06/01 13:30:35 obache Exp $

* for Lua 5.2 API change

--- lua/lmyoslib.c.orig	2012-06-12 06:02:01.000000000 +0000
+++ lua/lmyoslib.c
@@ -20,6 +20,13 @@
 #include "lualib.h"
 
 
+#ifdef LUA_VERSION_NUM
+# if (LUA_VERSION_NUM >= 502)
+#undef luaL_register
+#define luaL_register(L,n,f) \
+	{ if ((n) == NULL) luaL_setfuncs(L,f,0); else luaL_newlib(L,f); }
+# endif
+#endif
 
 /*
 ** {======================================================
