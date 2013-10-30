$NetBSD: patch-lua_lmyoslib.c,v 1.1 2013/10/30 11:30:37 obache Exp $

* for Lua 5.2 API change

--- lua/lmyoslib.c.orig	2012-06-01 15:47:06.000000000 +0000
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
