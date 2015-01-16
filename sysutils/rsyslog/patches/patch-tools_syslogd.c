$NetBSD: patch-tools_syslogd.c,v 1.3 2015/01/16 16:58:28 fhajny Exp $

Need errno.h on NetBSD. Fix default PID path.
--- tools/syslogd.c.orig	2014-12-02 10:15:16.000000000 +0000
+++ tools/syslogd.c
@@ -58,15 +58,19 @@
 #include <time.h>
 #include <assert.h>
 
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(OS_BSD)
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
