$NetBSD: patch-source_lua_Script.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/Script.cpp.orig	2024-10-02 09:59:31.629499454 +0000
+++ source/lua/Script.cpp
@@ -18,8 +18,7 @@
 
 #include "Script.h"
 #include <sstream>
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 #include <iostream>
 using namespace std;
 namespace lua
