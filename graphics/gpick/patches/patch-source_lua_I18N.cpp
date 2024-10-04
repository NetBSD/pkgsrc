$NetBSD: patch-source_lua_I18N.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/I18N.cpp.orig	2024-10-02 09:58:51.304564533 +0000
+++ source/lua/I18N.cpp
@@ -18,8 +18,7 @@
 
 #include "I18N.h"
 #include "../I18N.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua
 {
 int getText(lua_State *L)
