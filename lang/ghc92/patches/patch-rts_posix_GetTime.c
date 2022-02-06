$NetBSD: patch-rts_posix_GetTime.c,v 1.1 2022/02/06 05:36:16 pho Exp $

OmniOS defines CLOCK_THREAD_CPUTIME_ID but it isn't actually usable:
clock_gettime(2) always returns EINVAL. Use Solaris-specific
gethrvtime(3) instead.

Sent to the upstream:
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/5678

--- rts/posix/GetTime.c.orig	2021-04-29 21:06:04.382045075 +0000
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
@@ -81,6 +85,8 @@ Time getCurrentThreadCPUTime(void)
         sysErrorBelch("getThreadCPUTime");
         stg_exit(EXIT_FAILURE);
     }
+#elif defined(solaris2_HOST_OS)
+    return NSToTime(gethrvtime());
 #elif defined(HAVE_CLOCK_GETTIME)        &&  \
        defined(CLOCK_PROCESS_CPUTIME_ID) &&  \
        defined(HAVE_SYSCONF)
