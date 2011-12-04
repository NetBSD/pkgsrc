$NetBSD: patch-unix-pmachdep.h,v 1.1 2011/12/04 21:59:37 marino Exp $

--- include/ptlib/unix/ptlib/pmachdep.h.orig	2009-09-21 00:25:51.000000000 +0000
+++ include/ptlib/unix/ptlib/pmachdep.h
@@ -62,6 +62,34 @@ typedef size_t socklen_t;
 #endif
 
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
