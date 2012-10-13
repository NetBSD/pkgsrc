$NetBSD: patch-unix-pmachdep.h,v 1.2 2012/10/13 00:49:38 darcy Exp $

- Add DragonFly support

--- include/ptlib/unix/ptlib/pmachdep.h.orig	2012-08-23 02:12:57.000000000 +0000
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
