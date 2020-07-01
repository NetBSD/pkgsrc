$NetBSD: patch-cmake_FindLua.cmake,v 1.1 2020/07/01 10:06:42 nia Exp $

Avoid finding unversioned Lua in NetBSD.

--- cmake/FindLua.cmake.orig	2019-01-05 19:54:35.000000000 +0000
+++ cmake/FindLua.cmake
@@ -31,16 +31,11 @@
 # standard syntax, e.g. FIND_PACKAGE(Lua 5.1)
 # Otherwise the module will search for any available Lua implementation
 
-# Always search for non-versioned lua first (recommended)
-SET(_POSSIBLE_LUA_INCLUDE include include/lua)
-SET(_POSSIBLE_LUA_EXECUTABLE lua)
-SET(_POSSIBLE_LUA_LIBRARY lua)
-
 # Determine possible naming suffixes (there is no standard for this)
 IF(Lua_FIND_VERSION_MAJOR AND Lua_FIND_VERSION_MINOR)
-	SET(_POSSIBLE_SUFFIXES "${Lua_FIND_VERSION_MAJOR}${Lua_FIND_VERSION_MINOR}" "${Lua_FIND_VERSION_MAJOR}.${Lua_FIND_VERSION_MINOR}" "-${Lua_FIND_VERSION_MAJOR}.${Lua_FIND_VERSION_MINOR}")
+	SET(_POSSIBLE_SUFFIXES "${Lua_FIND_VERSION_MAJOR}.${Lua_FIND_VERSION_MINOR}" "-${Lua_FIND_VERSION_MAJOR}.${Lua_FIND_VERSION_MINOR}")
 ELSE(Lua_FIND_VERSION_MAJOR AND Lua_FIND_VERSION_MINOR)
-	SET(_POSSIBLE_SUFFIXES "53" "5.3" "-5.3")
+	SET(_POSSIBLE_SUFFIXES "5.3" "-5.3")
 ENDIF(Lua_FIND_VERSION_MAJOR AND Lua_FIND_VERSION_MINOR)
 
 # Set up possible search names and locations
