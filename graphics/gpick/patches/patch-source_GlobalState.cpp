$NetBSD: patch-source_GlobalState.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/GlobalState.cpp.orig	2024-10-02 10:00:21.498694912 +0000
+++ source/GlobalState.cpp
@@ -37,8 +37,7 @@
 #include <filesystem>
 #include <stdlib.h>
 #include <glib/gstdio.h>
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 #include <fstream>
 #include <iostream>
 struct GlobalState::Impl {
