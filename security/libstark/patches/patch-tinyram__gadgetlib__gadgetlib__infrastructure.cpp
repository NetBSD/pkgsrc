$NetBSD: patch-tinyram__gadgetlib__gadgetlib__infrastructure.cpp,v 1.1 2019/10/28 17:46:58 agc Exp $

linux has backtrace()

--- tinyram/gadgetlib/gadgetlib/infrastructure.cpp	2019/10/19 04:23:13	1.1
+++ tinyram/gadgetlib/gadgetlib/infrastructure.cpp	2019/10/19 04:23:50
@@ -17,7 +17,7 @@
 #include <unistd.h>
 #include <cstdio>
 #endif
-#ifdef __GLIBC__
+#ifdef __linux__
 #include <execinfo.h> // backtraces
 #endif
 
@@ -81,7 +81,7 @@
 	}
 
 	void ErrorHandling::printStacktrace() {
-#ifdef __GNUC__
+#ifdef __linux__
 		std::cerr << "Stack trace (pipe through c++filt to demangle identifiers):" << std::endl;
 		const int maxFrames = 100;
 		void* frames[maxFrames];
@@ -92,7 +92,7 @@
 #else
 		//TODO make this available for Windows
 		std::cerr << "  (stack trace not available on this platform)" << std::endl;
-#endif // __GNUC__
+#endif // __linux__
 	}
 
 	/*****************************************************************************/
