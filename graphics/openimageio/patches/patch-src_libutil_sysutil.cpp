$NetBSD: patch-src_libutil_sysutil.cpp,v 1.4 2018/10/07 23:38:45 ryoon Exp $

--- src/libutil/sysutil.cpp.orig	2018-10-01 21:26:14.000000000 +0000
+++ src/libutil/sysutil.cpp
@@ -42,7 +42,7 @@
 # include <sys/ioctl.h>
 #endif
 
-#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__NetBSD__)
 # include <sys/types.h>
 # include <sys/resource.h>
 # include <sys/sysctl.h>
@@ -139,7 +139,7 @@ Sysutil::memory_used (bool resident)
         return counters.PagefileUsage;
     else return 0;
 
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
     // FIXME -- does somebody know a good method for figuring this out for
     // FreeBSD?
     return 0;   // Punt
@@ -195,7 +195,7 @@ Sysutil::physical_memory ()
     //        statex.ullTotalVirtual   Total virtual memory
     //        statex.ullAvailVirtual   Free virtual memory
 
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
     // man 3 sysctl   ...or...
     // http://www.freebsd.org/cgi/man.cgi?query=sysctl&sektion=3
     // FIXME -- Does this accept a size_t?  Or only an int?  I can't
@@ -259,6 +259,15 @@ Sysutil::this_program_path ()
     size_t cb = sizeof(filename);
     int r=1;
     sysctl(mib, 4, filename, &cb, NULL, 0);
+#elif defined(__NetBSD__)
+    int mib[4];
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = getpid();
+    mib[3] = KERN_PROC_PATHNAME;
+    size_t cb = sizeof(filename);
+    int r=1;
+    sysctl(mib, 4, filename, &cb, NULL, 0);
 #elif defined(__GNU__) || defined(__OpenBSD__)
     int r = 0;
 #else
