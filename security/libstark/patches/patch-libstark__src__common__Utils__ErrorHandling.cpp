$NetBSD: patch-libstark__src__common__Utils__ErrorHandling.cpp,v 1.2 2023/07/12 21:19:27 nia Exp $

Include stdexcept for std::runtime_error.

backtrace() available on linux

--- libstark/src/common/Utils/ErrorHandling.cpp.orig	2018-12-11 08:57:02.000000000 +0000
+++ libstark/src/common/Utils/ErrorHandling.cpp
@@ -9,6 +9,7 @@
  */
   /************************************************************************************************************/
 #include <iostream>
+#include <stdexcept>
 #ifndef WIN32
 #include <unistd.h>
 #endif
@@ -53,7 +54,7 @@ void ErrorHandling::info(const stringstr
 }
 
 void ErrorHandling::printStacktrace() {
-#ifdef __GNUC__
+#ifdef __linux__
 	cerr << "Stack trace (pipe through c++filt to demangle identifiers):" << endl;
 	const int maxFrames = 100;
 	void* frames[maxFrames];
