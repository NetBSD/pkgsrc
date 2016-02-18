$NetBSD: patch-alsaloop_alsaloop.c,v 1.3 2016/02/18 15:16:33 wiz Exp $

--- alsaloop/alsaloop.c.orig	2015-10-27 16:34:26.000000000 +0000
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
 #include <signal.h>
 #include "alsaloop.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE	EPIPE
+#endif
+
 struct loopback_thread {
 	int threaded;
 	pthread_t thread;
