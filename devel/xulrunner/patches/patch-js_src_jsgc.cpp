$NetBSD: patch-js_src_jsgc.cpp,v 1.2 2012/08/28 12:42:01 ryoon Exp $

http://gnats.netbsd.org/46622

--- js/src/jsgc.cpp.orig	2012-08-08 20:20:14.000000000 +0000
+++ js/src/jsgc.cpp
@@ -2635,8 +2635,12 @@ GetCPUCount()
         GetSystemInfo(&sysinfo);
         ncpus = unsigned(sysinfo.dwNumberOfProcessors);
 # else
+#  ifdef _SC_NPROCESSORS_ONLN
         long n = sysconf(_SC_NPROCESSORS_ONLN);
         ncpus = (n > 0) ? unsigned(n) : 1;
+#  else
+       ncpus = 1;
+#  endif
 # endif
     }
     return ncpus;
