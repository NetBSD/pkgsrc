$NetBSD: patch-source_tools_lib_errorout.cpp,v 1.1 2011/11/23 23:29:45 joerg Exp $

--- source/tools/lib/errorout.cpp.orig	2011-11-23 16:28:24.000000000 +0000
+++ source/tools/lib/errorout.cpp
@@ -10,6 +10,7 @@
 #include <iostream>
 #include <cstdio>
 #include <cstdarg>
+#include <cstdlib>
 
 #ifdef _WIN32_
 # include <windows.h>
