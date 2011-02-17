$NetBSD: patch-avidemux_ADM_core_src_ADM_cpuCap.cpp,v 1.1 2011/02/17 09:20:17 markd Exp $

--- avidemux/ADM_core/src/ADM_cpuCap.cpp.orig	2009-04-02 13:24:10.000000000 +0000
+++ avidemux/ADM_core/src/ADM_cpuCap.cpp
@@ -15,6 +15,9 @@
 #include <pthread.h>
 #elif defined(__APPLE__) || defined(ADM_BSD_FAMILY)
 #include <sys/types.h>
+#ifdef free
+#undef free
+#endif
 #include <sys/sysctl.h>
 #else
 #include <string.h>
