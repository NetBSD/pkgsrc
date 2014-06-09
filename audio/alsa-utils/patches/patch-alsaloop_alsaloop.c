$NetBSD: patch-alsaloop_alsaloop.c,v 1.1 2014/06/09 12:34:26 ryoon Exp $

--- alsaloop/alsaloop.c.orig	2013-07-09 15:28:37.000000000 +0000
+++ alsaloop/alsaloop.c
@@ -24,6 +24,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sched.h>
+/* For ERESTART */
+#if defined(__NetBSD__)
+#define _KMEMUSER	1
+#endif
 #include <errno.h>
 #include <getopt.h>
 #include <alsa/asoundlib.h>
@@ -34,6 +38,10 @@
 #include <sys/signal.h>
 #include "alsaloop.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE	EPIPE
+#endif
+
 struct loopback_thread {
 	int threaded;
 	pthread_t thread;
