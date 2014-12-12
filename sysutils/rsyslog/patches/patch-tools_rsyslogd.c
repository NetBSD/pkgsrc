$NetBSD: patch-tools_rsyslogd.c,v 1.2 2014/12/12 12:47:46 fhajny Exp $

Need errno.h on NetBSD. Default PID file path.
--- tools/rsyslogd.c.orig	2014-12-02 10:15:16.000000000 +0000
+++ tools/rsyslogd.c
@@ -27,7 +27,7 @@
 #include <signal.h>
 #include <sys/wait.h>
 #include <liblogging/stdlog.h>
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(__NetBSD__)
 #	include <errno.h>
 #else
 #	include <sys/errno.h>
@@ -84,7 +84,7 @@ void rsyslogdDoDie(int sig);
 
 
 #ifndef PATH_PIDFILE
-#	define PATH_PIDFILE "/var/run/rsyslogd.pid"
+#	define PATH_PIDFILE "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #endif
 
 /* global data items */
