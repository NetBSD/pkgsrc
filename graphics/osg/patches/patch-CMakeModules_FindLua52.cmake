$NetBSD: patch-CMakeModules_FindLua52.cmake,v 1.1 2021/03/02 09:41:56 adam Exp $

Find Lua from PkgSrc.

--- CMakeModules/FindLua52.cmake.orig	2021-03-02 08:52:23.000000000 +0000
+++ CMakeModules/FindLua52.cmake
@@ -28,7 +28,7 @@
 find_path(LUA_INCLUDE_DIR lua.h
   HINTS
     ENV LUA_DIR
-  PATH_SUFFIXES include/lua52 include/lua5.2 include/lua include
+  PATH_SUFFIXES include/lua52 include/lua5.2 include/lua-5.2 include/lua include
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
