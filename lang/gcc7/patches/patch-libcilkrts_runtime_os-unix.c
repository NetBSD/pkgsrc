$NetBSD: patch-libcilkrts_runtime_os-unix.c,v 1.1 2017/05/03 00:21:03 maya Exp $

NetBSD doesn't need additional include files too
NetBSD can also obtain number of online cpus from sysconf
NetBSD can use sched_yield for sleeping

--- libcilkrts/runtime/os-unix.c.orig	2016-12-01 14:48:49.000000000 +0000
+++ libcilkrts/runtime/os-unix.c
@@ -73,6 +73,7 @@
 #elif defined __CYGWIN__ || \
       defined __DragonFly__ || \
       defined __FreeBSD__ || \
+      defined __NetBSD__ || \
       defined __GNU__
 // No additional include files
 
@@ -397,6 +398,7 @@ COMMON_SYSDEP int __cilkrts_hardware_cpu
     defined __CYGWIN__   || \
     defined __DragonFly__  || \
     defined __FreeBSD__  || \
+    defined __NetBSD__ || \
     (defined(__sun__) && defined(__svr4__))
     return (int)sysconf(_SC_NPROCESSORS_ONLN);
 #elif defined __MIC__
@@ -426,6 +428,7 @@ COMMON_SYSDEP void __cilkrts_idle(void)
     // silencing workers that are not stealing work.
 #if defined(__ANDROID__)  || \
     defined(__FreeBSD__)  || \
+    defined(__NetBSD__)   || \
     defined(__VXWORKS__)  || \
     (defined(__sun__) && defined(__svr4__))
     sched_yield();
@@ -456,6 +459,7 @@ COMMON_SYSDEP void __cilkrts_yield(void)
     defined(__APPLE__)    || \
     defined(__CYGWIN__)   || \
     defined(__FreeBSD__)  || \
+    defined(__NetBSD__)   || \
     defined(__VXWORKS__)  || \
     (defined(__sun__) && defined(__svr4__))
     // Call sched_yield to yield quantum.  I'm not sure why we
