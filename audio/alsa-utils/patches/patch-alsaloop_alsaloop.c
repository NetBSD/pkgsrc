$NetBSD: patch-alsaloop_alsaloop.c,v 1.4 2023/11/23 16:15:04 ryoon Exp $

--- alsaloop/alsaloop.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ alsaloop/alsaloop.c
@@ -25,6 +25,16 @@
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
@@ -36,6 +46,10 @@
 #include "alsaloop.h"
 #include "os_compat.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE	EPIPE
+#endif
+
 struct loopback_thread {
 	int threaded;
 	pthread_t thread;
@@ -821,7 +835,7 @@ static void send_to_all(int sig)
 	}
 }
 
-static void signal_handler(int)
+static void signal_handler(int sig ATTRIBUTE_UNUSED)
 {
 	quit = 1;
 	send_to_all(SIGUSR2);
