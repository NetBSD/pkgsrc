$NetBSD: patch-source_lua_Extensions.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/Extensions.cpp.orig	2024-10-02 09:58:36.188371927 +0000
+++ source/lua/Extensions.cpp
@@ -31,8 +31,7 @@
 #include "../Converters.h"
 #include "../Converter.h"
 #include "version/Version.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua
 {
 static void checkArgumentIsFunctionOrNil(lua_State *L, int index)
