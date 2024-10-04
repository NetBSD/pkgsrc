$NetBSD: patch-source_uiDialogOptions.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/uiDialogOptions.cpp.orig	2024-10-02 10:00:56.519023699 +0000
+++ source/uiDialogOptions.cpp
@@ -28,8 +28,7 @@
 #include "lua/Callbacks.h"
 #include <string>
 #include <iostream>
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 using namespace std;
 static const struct{
 	const char *label;
