$NetBSD: patch-rts_posix_GetTime.c,v 1.1 2021/09/30 13:23:48 jperkin Exp $

Backport SunOS fix from trunk.

--- rts/posix/GetTime.c.orig	2020-12-04 20:04:01.000000000 +0000
+++ rts/posix/GetTime.c
@@ -32,6 +32,10 @@
 #include <mach/mach_port.h>
 #endif
 
+#if defined(solaris2_HOST_OS)
+#include <sys/time.h>
+#endif
+
 #if defined(HAVE_GETTIMEOFDAY) && defined(HAVE_GETRUSAGE)
 // we'll implement getProcessCPUTime() and getProcessElapsedTime()
 // separately, using getrusage() and gettimeofday() respectively
@@ -81,6 +85,12 @@ Time getCurrentThreadCPUTime(void)
         sysErrorBelch("getThreadCPUTime");
         stg_exit(EXIT_FAILURE);
     }
+#elif defined(solaris2_HOST_OS)
+    // On OpenSolaris derivatives, the constant CLOCK_THREAD_CPUTIME_ID is
+    // defined in a system header but it isn't actually usable. clock_gettime(2)
+    // always returns EINVAL. Use solaris-specific gethrvtime(3) as an
+    // alternative.
+    return NSToTime(gethrvtime());
 #elif defined(HAVE_CLOCK_GETTIME)        &&  \
        defined(CLOCK_PROCESS_CPUTIME_ID) &&  \
        defined(HAVE_SYSCONF)
