$NetBSD: patch-avahi-daemon_main.c,v 1.1 2015/01/07 13:55:45 wiedi Exp $

Newer illumos has inotify and the inotify code needs FIONREAD

--- avahi-daemon/main.c.orig	2010-11-18 03:00:26.288465933 +0000
+++ avahi-daemon/main.c
@@ -31,6 +31,9 @@
 #include <grp.h>
 #include <pwd.h>
 #include <sys/stat.h>
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
 #include <sys/ioctl.h>
 #include <stdio.h>
 #include <fcntl.h>
