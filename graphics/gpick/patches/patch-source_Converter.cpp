$NetBSD: patch-source_Converter.cpp,v 1.1 2024/10/04 04:17:38 ryoon Exp $

--- source/Converter.cpp.orig	2024-10-02 10:01:14.451815447 +0000
+++ source/Converter.cpp
@@ -33,8 +33,7 @@
 #include <vector>
 #include <iostream>
 #include <functional>
-#include <lualib.h>
-#include <lauxlib.h>
+#include <lua.hpp>
 using namespace std;
 Converter::Converter(const char *name, const char *label, lua::Ref &&serialize, lua::Ref &&deserialize):
 	m_name(name),
