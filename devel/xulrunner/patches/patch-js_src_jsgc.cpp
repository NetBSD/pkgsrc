$NetBSD: patch-js_src_jsgc.cpp,v 1.4 2013/01/10 15:01:31 ryoon Exp $

http://gnats.netbsd.org/46622

--- js/src/jsgc.cpp.orig	2013-01-04 23:44:35.000000000 +0000
+++ js/src/jsgc.cpp
@@ -2905,8 +2905,12 @@ GetCPUCount()
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
