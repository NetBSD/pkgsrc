$NetBSD: patch-lib_tcpwrap.c,v 1.1 2022/12/15 13:58:02 vins Exp $

Define missing logging variables for libwrap on NetBSD.

--- lib/tcpwrap.c.orig	2022-02-12 15:20:43.000000000 +0000
+++ lib/tcpwrap.c
@@ -35,6 +35,12 @@ const char *mu_tcp_wrapper_daemon;
 
 #ifdef WITH_LIBWRAP
 # include <tcpd.h>
+# include <syslog.h>
+# if defined (__NetBSD__)
+#  include <syslog.h>
+   int allow_severity = LOG_INFO;
+   int deny_severity = LOG_WARNING;
+# endif
 
 int
 mu_tcpwrapper_access (int fd)
