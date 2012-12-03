$NetBSD: patch-include_tbb_tbb__misc.h,v 1.1 2012/12/03 12:54:14 ryoon Exp $

--- include/tbb/tbb_misc.h.orig	2012-11-16 23:02:42.000000000 +0000
+++ include/tbb/tbb_misc.h
@@ -42,7 +42,7 @@
 #elif defined(__APPLE__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 
@@ -64,11 +64,11 @@ static inline int DetectNumberOfWorkers(
     return static_cast<int>(si.dwNumberOfProcessors);
 }
 
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun) 
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun) || defined(__NetBSD__)
 static inline int DetectNumberOfWorkers() {
     long number_of_workers;
 
-#if (defined(__FreeBSD__) || defined(__sun)) && defined(_SC_NPROCESSORS_ONLN) 
+#if (defined(__FreeBSD__) || defined(__sun) || defined(__NetBSD__)) && defined(_SC_NPROCESSORS_ONLN) 
     number_of_workers = sysconf(_SC_NPROCESSORS_ONLN);
 
 // In theory, sysconf should work everywhere.
