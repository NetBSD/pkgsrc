$NetBSD: patch-tools_rsyslogd.c,v 1.4 2016/10/20 10:05:11 fhajny Exp $

Need errno.h on NetBSD. Default PID file path.
--- tools/rsyslogd.c.orig	2016-08-23 12:15:33.000000000 +0000
+++ tools/rsyslogd.c
@@ -32,7 +32,7 @@
 #else
 #  include <syslog.h>
 #endif
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(OS_BSD)
 #	include <errno.h>
 #else
 #	include <sys/errno.h>
@@ -89,7 +89,7 @@ void rsyslogdDoDie(int sig);
 
 
 #ifndef PATH_PIDFILE
-#	define PATH_PIDFILE "/var/run/rsyslogd.pid"
+#	define PATH_PIDFILE "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #endif
 
 /* global data items */
