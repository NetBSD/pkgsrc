$NetBSD: patch-libcilkrts_runtime_os-unix.c,v 1.1 2016/09/12 22:13:54 maya Exp $

--- libcilkrts/runtime/os-unix.c.orig	2014-05-21 11:08:58.000000000 +0000
+++ libcilkrts/runtime/os-unix.c
@@ -56,7 +56,9 @@
     // Uses sysconf(_SC_NPROCESSORS_ONLN) in verbose output
 #elif defined  __DragonFly__
 // No additional include files
-#elif defined  __FreeBSD__
+#elif defined  __FreeBSD__ 
+// No additional include files
+#elif defined  __NetBSD__ 
 // No additional include files
 #elif defined __CYGWIN__
 // Cygwin on Windows - no additional include files
@@ -376,7 +378,7 @@ COMMON_SYSDEP int __cilkrts_hardware_cpu
     assert((unsigned)count == count);
 
     return count;
-#elif defined  __FreeBSD__ || defined __CYGWIN__ || defined __DragonFly__
+#elif defined  __FreeBSD__ || defined __CYGWIN__ || defined __DragonFly__ || defined __NetBSD__
     int ncores = sysconf(_SC_NPROCESSORS_ONLN);
 
     return ncores;
@@ -400,7 +402,7 @@ COMMON_SYSDEP void __cilkrts_sleep(void)
 
 COMMON_SYSDEP void __cilkrts_yield(void)
 {
-#if __APPLE__ || __FreeBSD__ || __VXWORKS__
+#if __APPLE__ || __FreeBSD__ || __NetBSD__ || __VXWORKS__
     // On MacOS, call sched_yield to yield quantum.  I'm not sure why we
     // don't do this on Linux also.
     sched_yield();
