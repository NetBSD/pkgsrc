$NetBSD: patch-tools_rsyslogd.c,v 1.3 2015/01/16 16:58:28 fhajny Exp $

Need errno.h on NetBSD. Default PID file path.
--- tools/rsyslogd.c.orig	2015-01-12 08:49:44.000000000 +0000
+++ tools/rsyslogd.c
@@ -29,7 +29,7 @@
 #ifdef HAVE_LIBLOGGING_STDLOG
 #  include <liblogging/stdlog.h>
 #endif
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(OS_BSD)
 #	include <errno.h>
 #else
 #	include <sys/errno.h>
@@ -87,7 +87,7 @@ void rsyslogdDoDie(int sig);
 
 
 #ifndef PATH_PIDFILE
-#	define PATH_PIDFILE "/var/run/rsyslogd.pid"
+#	define PATH_PIDFILE "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #endif
 
 /* global data items */
