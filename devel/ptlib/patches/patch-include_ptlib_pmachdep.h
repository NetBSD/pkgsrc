$NetBSD: patch-include_ptlib_pmachdep.h,v 1.2 2012/10/17 10:26:16 jperkin Exp $

- Prevent an annoying warning while building

--- include/ptlib/unix/ptlib/pmachdep.h.orig	2012-08-23 02:12:57.000000000 +0000
+++ include/ptlib/unix/ptlib/pmachdep.h
@@ -112,7 +112,9 @@ typedef int socklen_t;
 #elif defined(P_OPENBSD)
 
 #if defined(P_PTHREADS)
+#ifndef _THREAD_SAFE
 #define _THREAD_SAFE
+#endif
 #define P_THREAD_SAFE_CLIB
 
 #include <pthread.h>
@@ -137,7 +139,9 @@ typedef int socklen_t;
 #elif defined(P_NETBSD)
 
 #if defined(P_PTHREADS)
+#ifndef _THREAD_SAFE
 #define _THREAD_SAFE
+#endif
 #define P_THREAD_SAFE_CLIB
 
 #include <pthread.h>
@@ -447,7 +451,9 @@ struct hostent * Vx_gethostbyaddr(char *
 #define strcasecmp strcmp
 
 #define P_HAS_SEMAPHORES
+#ifndef _THREAD_SAFE
 #define _THREAD_SAFE
+#endif
 #define P_THREAD_SAFE_CLIB
 typedef long PThreadIdentifier;
 typedef long PProcessIdentifier;
@@ -481,7 +487,9 @@ extern "C" {
 #elif defined(P_QNX)
 
 #if defined(P_PTHREADS)
+#ifndef _THREAD_SAFE
 #define _THREAD_SAFE
+#endif
 #define P_THREAD_SAFE_CLIB
 
 #include <pthread.h>
