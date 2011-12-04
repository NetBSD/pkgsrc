$NetBSD: patch-Nucleus-pmachdep.h,v 1.1 2011/12/04 21:59:36 marino Exp $

--- include/ptlib/Nucleus++/ptlib/pmachdep.h.orig	2009-09-21 00:25:51.000000000 +0000
+++ include/ptlib/Nucleus++/ptlib/pmachdep.h
@@ -62,6 +62,34 @@ typedef size_t socklen_t;
 #endif
 
 ///////////////////////////////////////////////////////////////////////////////
+#elif defined(P_DRAGONFLY)
+
+#if defined(P_PTHREADS)
+#define _THREAD_SAFE
+#define P_THREAD_SAFE_CLIB
+
+#include <pthread.h>
+extern "C" int sigwait(sigset_t *set);
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
+
+#define HAS_IFREQ
+
+#define PSETPGRP()  setpgrp(0, 0)
+
+typedef int socklen_t;
+
+///////////////////////////////////////////////////////////////////////////////
 #elif defined(P_FREEBSD)
 
 #if defined(P_PTHREADS)
