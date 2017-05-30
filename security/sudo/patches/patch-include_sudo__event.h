$NetBSD: patch-include_sudo__event.h,v 1.1 2017/05/30 16:14:56 maya Exp $

Missing include, fixes build error:
error: field 'timeout' has incomplete type
struct timeval timeout; /* for SUDO_EV_TIMEOUT */

--- include/sudo_event.h.orig	2017-01-14 04:30:15.000000000 +0000
+++ include/sudo_event.h
@@ -18,6 +18,7 @@
 #define SUDO_EVENT_H
 
 #include "sudo_queue.h"
+#include <sys/time.h> /* timeval */
 
 /* Event types */
 #define SUDO_EV_TIMEOUT		0x01	/* fire after timeout */
