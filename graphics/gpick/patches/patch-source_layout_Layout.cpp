$NetBSD: patch-source_layout_Layout.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/layout/Layout.cpp.orig	2024-10-02 10:01:34.779610928 +0000
+++ source/layout/Layout.cpp
@@ -20,8 +20,7 @@
 #include "System.h"
 #include "../lua/Layout.h"
 #include <iostream>
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 using namespace std;
 namespace layout
 {
