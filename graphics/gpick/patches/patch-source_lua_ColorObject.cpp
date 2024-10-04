$NetBSD: patch-source_lua_ColorObject.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/ColorObject.cpp.orig	2024-10-02 10:00:04.277116526 +0000
+++ source/lua/ColorObject.cpp
@@ -20,8 +20,7 @@
 #include "Color.h"
 #include "Script.h"
 #include "../ColorObject.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua
 {
 static int newColorObject(lua_State *L)
