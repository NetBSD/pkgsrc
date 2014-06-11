$NetBSD: patch-alsaloop_alsaloop.c,v 1.2 2014/06/11 14:45:09 ryoon Exp $

--- alsaloop/alsaloop.c.orig	2013-07-09 15:28:37.000000000 +0000
+++ alsaloop/alsaloop.c
@@ -24,6 +24,16 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sched.h>
+/* For ERESTART */
+#if defined(__NetBSD__)
+#include <sys/param.h>
+/* NetBSD 6 does not have _KMEMUSER. And _KERNEL breaks build of alsa-utils. */
+#if __NetBSD_Version__ < 699000000
+#define ERESTART	-3
+#else
+#define _KMEMUSER	1
+#endif
+#endif
 #include <errno.h>
 #include <getopt.h>
 #include <alsa/asoundlib.h>
@@ -34,6 +44,10 @@
 #include <sys/signal.h>
 #include "alsaloop.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE	EPIPE
+#endif
+
 struct loopback_thread {
 	int threaded;
 	pthread_t thread;
