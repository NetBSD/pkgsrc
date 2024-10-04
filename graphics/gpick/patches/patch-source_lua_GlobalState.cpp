$NetBSD: patch-source_lua_GlobalState.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/GlobalState.cpp.orig	2024-10-02 09:58:18.420701457 +0000
+++ source/lua/GlobalState.cpp
@@ -18,8 +18,7 @@
 
 #include "GlobalState.h"
 #include "../GlobalState.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua
 {
 void setGlobalState(lua_State *L, GlobalState &global_state)
