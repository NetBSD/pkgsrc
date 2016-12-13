$NetBSD: patch-src_inotify.c,v 1.1 2016/12/13 13:40:05 wiedi Exp $

need sys/filio.h for FIONREAD on SunOS

--- src/inotify.c.orig	2016-06-29 09:49:22.000000000 +0000
+++ src/inotify.c
@@ -27,6 +27,10 @@ along with GNU Emacs.  If not, see <http
 #include "keyboard.h"
 #include "termhooks.h"
 
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
+
 #include <errno.h>
 #include <sys/inotify.h>
 #include <sys/ioctl.h>
