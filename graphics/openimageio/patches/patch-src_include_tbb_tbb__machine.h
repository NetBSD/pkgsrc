$NetBSD: patch-src_include_tbb_tbb__machine.h,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/include/tbb/tbb_machine.h.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/include/tbb/tbb_machine.h
@@ -53,7 +53,7 @@ extern "C" __declspec(dllimport) int __s
 #pragma managed(pop)
 #endif
 
-#elif __linux__ || __FreeBSD__
+#elif __linux__ || __FreeBSD__ || __NetBSD__
 
 #if __i386__
 #include "machine/linux_ia32.h"
