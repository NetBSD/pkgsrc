$NetBSD: patch-source_lua_Layout.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/Layout.cpp.orig	2024-10-02 09:59:48.709013394 +0000
+++ source/lua/Layout.cpp
@@ -23,8 +23,7 @@
 #include "../layout/Box.h"
 #include "../layout/System.h"
 #include "../layout/Layout.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 #include <typeinfo>
 #include <iostream>
 using namespace std;
