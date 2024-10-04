$NetBSD: patch-source_lua_DynvSystem.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/DynvSystem.cpp.orig	2024-10-02 09:59:17.766079227 +0000
+++ source/lua/DynvSystem.cpp
@@ -17,8 +17,7 @@
  */
 
 #include "DynvSystem.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua {
 dynv::Ref checkDynvSystem(lua_State *L, int index) {
 	void *ud = luaL_checkudata(L, index, "dynvSystem");
