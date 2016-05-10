$NetBSD: patch-avahi-daemon_main.c,v 1.3 2016/05/10 18:52:17 jperkin Exp $

Provide O_CLOEXEC compat define.

--- avahi-daemon/main.c.orig	2015-10-09 23:51:25.000000000 +0000
+++ avahi-daemon/main.c
@@ -87,6 +87,10 @@
 #include "dbus-protocol.h"
 #endif
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 AvahiServer *avahi_server = NULL;
 AvahiSimplePoll *simple_poll_api = NULL;
 static char *argv0 = NULL;
