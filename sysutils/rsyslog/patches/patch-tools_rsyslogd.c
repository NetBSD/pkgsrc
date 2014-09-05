$NetBSD: patch-tools_rsyslogd.c,v 1.1 2014/09/05 07:15:41 fhajny Exp $

Need errno.h on NetBSD.
--- tools/rsyslogd.c.orig	2014-08-18 09:14:06.000000000 +0000
+++ tools/rsyslogd.c
@@ -26,7 +26,7 @@
 
 #include <signal.h>
 #include <liblogging/stdlog.h>
-#ifdef OS_SOLARIS
+#if defined(OS_SOLARIS) || defined(__NetBSD__)
 #	include <errno.h>
 #else
 #	include <sys/errno.h>
