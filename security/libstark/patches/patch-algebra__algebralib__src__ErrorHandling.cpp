$NetBSD: patch-algebra__algebralib__src__ErrorHandling.cpp,v 1.1 2019/10/28 17:46:58 agc Exp $

Linux has backtrace(), so change the cpp definition

--- algebra/algebralib/src/ErrorHandling.cpp	2019/10/19 04:04:58	1.1
+++ algebra/algebralib/src/ErrorHandling.cpp	2019/10/19 04:05:39
@@ -79,7 +79,7 @@
 	}
 
 	void ErrorHandling::printStacktrace() {
-#ifdef __GNUC__
+#ifdef __linux__
 		std::cerr << "Stack trace (pipe through c++filt to demangle identifiers):" << std::endl;
 		const int maxFrames = 100;
 		void* frames[maxFrames];
