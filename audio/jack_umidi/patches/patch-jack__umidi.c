$NetBSD: patch-jack__umidi.c,v 1.1 2021/11/05 22:29:58 nia Exp $

Fix compilation on NetBSD.

--- jack_umidi.c.orig	2021-06-02 15:38:42.000000000 +0000
+++ jack_umidi.c
@@ -38,6 +38,7 @@
 #include <fcntl.h>
 #include <pthread.h>
 #include <err.h>
+#include <errno.h>
 #include <sysexits.h>
 #include <sys/errno.h>
 #ifdef HAVE_SYSCTL
@@ -513,8 +514,8 @@ umidi_watchdog_sub(void)
 	}
 }
 
-static void *
-umidi_watchdog(void *arg)
+static void
+umidi_watchdog(void)
 {
 	while (1) {
 		/* check if we should close */
@@ -751,7 +752,7 @@ retry:
 	if (jack_activate(jack_client))
 		errx(EX_UNAVAILABLE, "Cannot activate JACK client.");
 
-	umidi_watchdog(NULL);
+	umidi_watchdog();
 
 	return (0);
 }
