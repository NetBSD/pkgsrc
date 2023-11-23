$NetBSD: patch-alsaloop_pcmjob.c,v 1.3 2023/11/23 16:15:04 ryoon Exp $

--- alsaloop/pcmjob.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ alsaloop/pcmjob.c
@@ -26,6 +26,10 @@
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
@@ -36,6 +40,10 @@
 #include "alsaloop.h"
 #include "os_compat.h"
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE	EPIPE
+#endif
+
 #define XRUN_PROFILE_UNKNOWN (-10000000)
 
 static int set_rate_shift(struct loopback_handle *lhandle, double pitch);
@@ -625,7 +633,7 @@ static void buf_add_src(struct loopback 
 	}
 }
 #else
-static void buf_add_src(struct loopback *)
+static void buf_add_src(struct loopback *loop ATTRIBUTE_UNUSED)
 {
 }
 #endif
@@ -1794,7 +1802,7 @@ static int ctl_event_check(snd_ctl_elem_
 }
 
 static int handle_ctl_events(struct loopback_handle *lhandle,
-			     unsigned short)
+			     unsigned short events ATTRIBUTE_UNUSED)
 {
 	struct loopback *loop = lhandle->loopback;
 	snd_ctl_event_t *ev;
