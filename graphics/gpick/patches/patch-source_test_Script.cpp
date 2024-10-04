$NetBSD: patch-source_test_Script.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/test/Script.cpp.orig	2024-10-02 10:00:39.269947217 +0000
+++ source/test/Script.cpp
@@ -19,8 +19,7 @@
 #include <boost/test/unit_test.hpp>
 #include "lua/Script.h"
 #include "common/Scoped.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 using namespace lua;
 static int test(lua_State *L) {
 	lua_pushstring(L, "ok");
