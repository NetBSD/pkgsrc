$NetBSD: patch-source_lua_Ref.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/lua/Ref.cpp.orig	2024-10-02 10:01:52.073031305 +0000
+++ source/lua/Ref.cpp
@@ -17,8 +17,7 @@
  */
 
 #include "Ref.h"
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 namespace lua
 {
 Ref::Ref():
