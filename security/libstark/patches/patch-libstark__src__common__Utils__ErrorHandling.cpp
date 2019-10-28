$NetBSD: patch-libstark__src__common__Utils__ErrorHandling.cpp,v 1.1 2019/10/28 17:46:58 agc Exp $

backtrace() available on linux

--- libstark/src/common/Utils/ErrorHandling.cpp	2019/10/19 04:10:03	1.1
+++ libstark/src/common/Utils/ErrorHandling.cpp	2019/10/19 04:10:31
@@ -53,7 +53,7 @@
 }
 
 void ErrorHandling::printStacktrace() {
-#ifdef __GNUC__
+#ifdef __linux__
 	cerr << "Stack trace (pipe through c++filt to demangle identifiers):" << endl;
 	const int maxFrames = 100;
 	void* frames[maxFrames];
