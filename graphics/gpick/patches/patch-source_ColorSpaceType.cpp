$NetBSD: patch-source_ColorSpaceType.cpp,v 1.1 2024/10/04 04:17:37 ryoon Exp $

--- source/ColorSpaceType.cpp.orig	2024-10-02 09:41:24.365191141 +0000
+++ source/ColorSpaceType.cpp
@@ -22,7 +22,7 @@
 #include "lua/Color.h"
 #include "lua/Script.h"
 #include "lua/Callbacks.h"
-#include <lua.h>
+#include <lua.hpp>
 #include <iostream>
 using namespace std;
 
