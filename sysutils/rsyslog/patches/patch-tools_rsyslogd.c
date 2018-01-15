$NetBSD: patch-tools_rsyslogd.c,v 1.6 2018/01/15 11:01:16 fhajny Exp $

Default PID file path.

--- tools/rsyslogd.c.orig	2018-01-09 08:40:30.000000000 +0000
+++ tools/rsyslogd.c
@@ -148,7 +148,7 @@ void rsyslogdDoDie(int sig);
 #if defined(_AIX)  /* AIXPORT : Add _AIX */
 #	define PATH_PIDFILE "/etc/rsyslogd.pid"
 #else
-#	define PATH_PIDFILE "/var/run/rsyslogd.pid"
+#	define PATH_PIDFILE "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #endif /*_AIX*/
 #endif
 
