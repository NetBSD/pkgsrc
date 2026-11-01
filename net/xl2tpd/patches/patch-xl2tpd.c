$NetBSD: patch-xl2tpd.c,v 1.4 2026/11/01 17:52:34 christos Exp $

1. Expose functions
2. Open with O_RDWR instead of O_RDONLY so that select blocks.

--- xl2tpd.c.orig	2017-08-02 13:46:06.000000000 -0400
+++ xl2tpd.c	2026-11-01 12:44:14.097909457 -0500
@@ -20,6 +20,7 @@
 #define _DEFAULT_SOURCE
 #define _XOPEN_SOURCE_EXTENDED	1
 #define _GNU_SOURCE
+#define _NETBSD_SOURCE
 
 #include <stdlib.h>
 #include <sys/types.h>
@@ -1802,7 +1803,7 @@
 
 static void open_controlfd()
 {
-    control_fd = open (gconfig.controlfile, O_RDONLY | O_NONBLOCK, 0600);
+    control_fd = open (gconfig.controlfile, O_RDWR | O_NONBLOCK, 0600);
     if (control_fd < 0)
     {
         l2tp_log (LOG_CRIT, "%s: Unable to open %s for reading.\n",
@@ -1811,7 +1812,7 @@
     }
 
     /* turn off O_NONBLOCK */
-    if(fcntl(control_fd, F_SETFL, O_RDONLY)==-1) {
+    if(fcntl(control_fd, F_SETFL, O_RDWR)==-1) {
         l2tp_log(LOG_CRIT, "Can not turn off nonblocking mode for controlfd: %s\n",
                 strerror(errno));
         exit(1);
