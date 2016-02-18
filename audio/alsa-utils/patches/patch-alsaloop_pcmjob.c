$NetBSD: patch-alsaloop_pcmjob.c,v 1.2 2016/02/18 15:16:33 wiz Exp $

--- alsaloop/pcmjob.c.orig	2015-10-27 16:34:26.000000000 +0000
+++ alsaloop/pcmjob.c
@@ -25,6 +25,10 @@
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
 #include <pthread.h>
 #include "alsaloop.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE	EPIPE
+#endif
+
 #define XRUN_PROFILE_UNKNOWN (-10000000)
 
 static int set_rate_shift(struct loopback_handle *lhandle, double pitch);
