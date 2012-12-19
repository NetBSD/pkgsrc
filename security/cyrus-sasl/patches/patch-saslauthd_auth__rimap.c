$NetBSD: patch-saslauthd_auth__rimap.c,v 1.2 2012/12/19 10:46:56 obache Exp $

* include sys/time.h form `struct timeval'
  https://bugzilla.cyrusimap.org/show_bug.cgi?id=3758

--- saslauthd/auth_rimap.c.orig	2012-10-12 14:05:48.000000000 +0000
+++ saslauthd/auth_rimap.c
@@ -71,6 +71,7 @@
 #include <syslog.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <signal.h>
