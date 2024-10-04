$NetBSD: patch-source_lua_Color.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/Color.cpp.orig	2024-10-02 09:59:05.784850753 +0000
+++ source/lua/Color.cpp
@@ -18,8 +18,7 @@
 
 #include "Color.h"
 #include "../Color.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua
 {
 static int newColor(lua_State *L)
