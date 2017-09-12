$NetBSD: patch-include_sudo__event.h,v 1.2 2017/09/12 06:34:22 adam Exp $

Missing include, fixes build error:
error: field 'timeout' has incomplete type
struct timeval timeout; /* for SUDO_EV_TIMEOUT */

--- include/sudo_event.h.orig	2017-08-23 18:07:28.000000000 +0000
+++ include/sudo_event.h
@@ -19,6 +19,7 @@
 
 #include <signal.h>	/* for sigatomic_t and NSIG */
 #include "sudo_queue.h"
+#include <sys/time.h> /* timeval */
 
 /* Event types */
 #define SUDO_EV_TIMEOUT		0x01	/* fire after timeout */
