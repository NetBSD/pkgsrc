$NetBSD: patch-tools_rsyslogd.c,v 1.5 2017/02/13 19:59:36 fhajny Exp $

Need errno.h on NetBSD. Default PID file path.
--- tools/rsyslogd.c.orig	2017-01-10 09:00:04.000000000 +0000
+++ tools/rsyslogd.c
@@ -33,7 +33,7 @@
 #else
 #  include <syslog.h>
 #endif
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(OS_BSD)
 #	include <errno.h>
 #else
 #	include <sys/errno.h>
@@ -146,7 +146,7 @@ void rsyslogdDoDie(int sig);
 #if defined(_AIX)  /* AIXPORT : Add _AIX */
 #	define PATH_PIDFILE "/etc/rsyslogd.pid"
 #else
-#	define PATH_PIDFILE "/var/run/rsyslogd.pid"
+#	define PATH_PIDFILE "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #endif /*_AIX*/
 #endif
 
