$NetBSD: patch-rvt_ttyinit.c,v 1.1 2013/12/17 06:45:40 asau Exp $

--- rvt/ttyinit.c.orig	2007-01-24 19:02:10.000000000 +0000
+++ rvt/ttyinit.c	2013-12-17 06:40:04.802505132 +0000
@@ -41,7 +41,11 @@
 #include <unistd.h>
 #include <signal.h>
 #include <fcntl.h>
+#if defined(__FreeBSD__)
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 #include <grp.h>
 #include <pwd.h>
 #include <errno.h>
