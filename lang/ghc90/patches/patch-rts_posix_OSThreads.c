$NetBSD: patch-rts_posix_OSThreads.c,v 1.1 2021/04/22 14:20:24 pho Exp $

Implementation of getNumberOfProcessors() for NetBSD

TODO: Send this to the upstream.

--- rts/posix/OSThreads.c.orig	2021-04-22 12:36:33.476115260 +0000
+++ rts/posix/OSThreads.c
@@ -14,6 +14,11 @@
  * DragonflyBSD, because of some specific types, like u_char, u_int, etc. */
 #define __BSD_VISIBLE   1
 #endif
+#if defined(netbsd_HOST_OS)
+/* Inclusion of system headers usually requires _NETBSD_SOURCE on NetBSD,
+ * because of some specific types, like u_char, u_int, etc. */
+#define _NETBSD_SOURCE 1
+#endif
 #if defined(darwin_HOST_OS)
 /* Inclusion of system headers usually requires _DARWIN_C_SOURCE on Mac OS X
  * because of some specific types like u_char, u_int, etc. */
@@ -42,7 +47,7 @@
 #include <string.h>
 #endif
 
-#if defined(darwin_HOST_OS) || defined(freebsd_HOST_OS)
+#if defined(darwin_HOST_OS) || defined(freebsd_HOST_OS) || defined(netbsd_HOST_OS)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -279,6 +284,13 @@ getNumberOfProcessors (void)
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
