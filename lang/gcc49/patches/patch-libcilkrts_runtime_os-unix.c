$NetBSD: patch-libcilkrts_runtime_os-unix.c,v 1.1 2014/09/04 18:43:11 jperkin Exp $

Add NetBSD support.

--- libcilkrts/runtime/os-unix.c.orig	2014-04-17 11:52:44.000000000 +0000
+++ libcilkrts/runtime/os-unix.c
@@ -54,7 +54,7 @@
 #elif defined __APPLE__
 #   include <sys/sysctl.h>
     // Uses sysconf(_SC_NPROCESSORS_ONLN) in verbose output
-#elif defined  __FreeBSD__
+#elif defined  __FreeBSD__ || defined __NetBSD__
 // No additional include files
 #elif defined __CYGWIN__
 // Cygwin on Windows - no additional include files
@@ -374,7 +374,7 @@ COMMON_SYSDEP int __cilkrts_hardware_cpu
     assert((unsigned)count == count);
 
     return count;
-#elif defined  __FreeBSD__ || defined __CYGWIN__
+#elif defined  __FreeBSD__ || __NetBSD__ || defined __CYGWIN__
     int ncores = sysconf(_SC_NPROCESSORS_ONLN);
 
     return ncores;
@@ -398,7 +398,7 @@ COMMON_SYSDEP void __cilkrts_sleep(void)
 
 COMMON_SYSDEP void __cilkrts_yield(void)
 {
-#if __APPLE__ || __FreeBSD__ || __VXWORKS__
+#if __APPLE__ || __FreeBSD__ || __NetBSD__ || __VXWORKS__
     // On MacOS, call sched_yield to yield quantum.  I'm not sure why we
     // don't do this on Linux also.
     sched_yield();
