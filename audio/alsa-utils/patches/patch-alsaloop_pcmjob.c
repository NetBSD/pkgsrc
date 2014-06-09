$NetBSD: patch-alsaloop_pcmjob.c,v 1.1 2014/06/09 12:34:26 ryoon Exp $

--- alsaloop/pcmjob.c.orig	2013-07-09 15:28:37.000000000 +0000
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
@@ -63,7 +71,11 @@ static const char *src_types[] = {
 #endif
 
 static pthread_mutex_t pcm_open_mutex =
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
                                 PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+#else
+				PTHREAD_MUTEX_INITIALIZER;
+#endif
 
 static inline void pcm_open_lock(void)
 {
