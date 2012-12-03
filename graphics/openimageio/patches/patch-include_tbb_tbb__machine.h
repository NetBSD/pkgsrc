$NetBSD: patch-include_tbb_tbb__machine.h,v 1.1 2012/12/03 12:54:14 ryoon Exp $

--- include/tbb/tbb_machine.h.orig	2012-11-16 23:02:42.000000000 +0000
+++ include/tbb/tbb_machine.h
@@ -53,7 +53,7 @@ extern "C" __declspec(dllimport) int __s
 #pragma managed(pop)
 #endif
 
-#elif __linux__ || __FreeBSD__
+#elif __linux__ || __FreeBSD__ || __NetBSD__
 
 #if __i386__
 #include "machine/linux_ia32.h"
