$NetBSD: patch-rts_posix_OSThreads.c,v 1.3 2022/01/18 02:22:50 pho Exp $

Implementation of getNumberOfProcessors() for NetBSD

Sent to the upstream:
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/5679

--- rts/posix/OSThreads.c.orig	2021-09-15 15:27:32.000000000 +0000
+++ rts/posix/OSThreads.c
@@ -25,6 +25,11 @@
 #if defined(freebsd_HOST_OS) || defined(dragonfly_HOST_OS)
 #define __BSD_VISIBLE   1
 #endif
+#if defined(netbsd_HOST_OS)
+/* Inclusion of system headers usually requires _NETBSD_SOURCE on NetBSD,
+ * because of some specific types, like u_char, u_int, etc. */
+#define _NETBSD_SOURCE 1
+#endif
 #if defined(darwin_HOST_OS)
 #define _DARWIN_C_SOURCE 1
 #endif
@@ -51,7 +56,7 @@
 #include <string.h>
 #endif
 
-#if defined(darwin_HOST_OS) || defined(freebsd_HOST_OS)
+#if defined(darwin_HOST_OS) || defined(freebsd_HOST_OS) || defined(netbsd_HOST_OS)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -292,6 +297,13 @@ getNumberOfProcessors (void)
             if(sysctlbyname("hw.ncpu",&nproc,&size,NULL,0) != 0)
                 nproc = 1;
         }
+#elif defined(netbsd_HOST_OS)
+        size_t size = sizeof(uint32_t);
+        if (sysctlbyname("hw.ncpuonline", &nproc, &size, NULL, 0) != 0) {
+            if (sysctlbyname("hw.ncpu", &nproc, &size, NULL, 0) != 0) {
+                nproc = 1;
+            }
+        }
 #elif defined(HAVE_SYSCONF) && defined(_SC_NPROCESSORS_ONLN)
         // N.B. This is the number of physical processors.
         nproc = sysconf(_SC_NPROCESSORS_ONLN);
