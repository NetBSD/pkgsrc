$NetBSD: patch-js_src_jsgc.cpp,v 1.1 2012/07/14 21:19:48 ryoon Exp $

http://gnats.netbsd.org/46622

--- js/src/jsgc.cpp.orig	2012-06-01 12:04:04.000000000 +0000
+++ js/src/jsgc.cpp
@@ -2636,8 +2636,12 @@ GetCPUCount()
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
