$NetBSD: patch-unix-pmachdep.h,v 1.3 2016/07/19 12:46:06 jperkin Exp $

- Add DragonFly support

--- include/ptlib/unix/ptlib/pmachdep.h.orig	2016-07-19 12:34:32.470453722 +0000
+++ include/ptlib/unix/ptlib/pmachdep.h
@@ -78,6 +78,34 @@ typedef size_t socklen_t;
 #define HAS_IFREQ
 
 ///////////////////////////////////////////////////////////////////////////////
+#elif defined(P_DRAGONFLY)
+
+#if defined(P_PTHREADS)
+#ifndef _THREAD_SAFE
+#define _THREAD_SAFE
+#endif
+#define P_THREAD_SAFE_CLIB
+
+#include <pthread.h>
+#endif
+
+#include <paths.h>
+#include <errno.h>
+#include <dlfcn.h>
+#include <termios.h>
+#include <sys/fcntl.h>
+#include <sys/filio.h>
+#include <sys/socket.h>
+#include <sys/sockio.h>
+#include <sys/signal.h>
+#include <net/if.h>
+#include <netinet/tcp.h>
+
+#define HAS_IFREQ
+
+#define PSETPGRP()  setpgrp(0, 0)
+
+///////////////////////////////////////////////////////////////////////////////
 #elif defined(P_FREEBSD)
 
 #if defined(P_PTHREADS)
@@ -195,7 +223,9 @@ typedef union {
 } upad128_t;
 #endif
 
+#ifndef INADDR_NONE
 #define INADDR_NONE     -1
+#endif
 #if P_SOLARIS < 7
 typedef int socklen_t;
 #endif
