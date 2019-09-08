$NetBSD: patch-es-app_src_ScraperCmdLine.cpp,v 1.1 2019/09/08 12:34:38 nia Exp $

Support non-Linux unixes.

--- es-app/src/ScraperCmdLine.cpp.orig	2018-07-11 17:16:47.000000000 +0000
+++ es-app/src/ScraperCmdLine.cpp
@@ -5,10 +5,10 @@
 #include "SystemData.h"
 #include <iostream>
 #include <signal.h>
-#if defined(__linux__)
-#include <unistd.h>
-#elif defined(WIN32)
+#ifdef WIN32
 #include <Windows.h>
+#else
+#include <unistd.h>
 #endif
 
 std::ostream& out = std::cout;
