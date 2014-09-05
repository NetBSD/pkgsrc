$NetBSD: patch-tools_syslogd.c,v 1.1 2014/09/05 07:15:41 fhajny Exp $

Need errno.h on NetBSD. Fix default PID path.
--- tools/syslogd.c.orig	2014-07-15 13:34:03.000000000 +0000
+++ tools/syslogd.c
@@ -58,15 +58,19 @@
 #include <time.h>
 #include <assert.h>
 
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(__NetBSD__)
 #	include <errno.h>
+#else
+#	include <sys/errno.h>
+#endif
+
+#ifdef OS_SOLARIS
 #	include <fcntl.h>
 #	include <stropts.h>
 #	include <sys/termios.h>
 #	include <sys/types.h>
 #else
 #	include <libgen.h>
-#	include <sys/errno.h>
 #endif
 
 #include <sys/ioctl.h>
@@ -135,7 +139,7 @@ void rsyslogdDoDie(int sig);
 
 
 #ifndef _PATH_LOGPID
-#	define _PATH_LOGPID "/var/run/rsyslogd.pid"
+#	define _PATH_LOGPID "@RSYSLOG_PIDDIR@/rsyslogd.pid"
 #endif
 
 #ifndef _PATH_TTY
