$NetBSD: patch-components_crashcatcher_crashcatcher.cpp,v 1.1 2019/08/09 16:26:09 nia Exp $

Support NetBSD.

--- components/crashcatcher/crashcatcher.cpp.orig	2019-03-10 10:50:29.000000000 +0000
+++ components/crashcatcher/crashcatcher.cpp
@@ -28,7 +28,7 @@ namespace bfs = boost::filesystem;
 #ifndef PR_SET_PTRACER
 #define PR_SET_PTRACER 0x59616d61
 #endif
-#elif defined (__APPLE__) || defined (__FreeBSD__) || defined(__OpenBSD__)
+#elif defined (__APPLE__) || defined (__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 
