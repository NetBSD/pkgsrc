$NetBSD: patch-plugin_xlib_gvdevice__xlib.c,v 1.1 2015/01/31 23:25:26 jperkin Exp $

SunOS inotify requires sys/filio.h for FIONREAD.

--- plugin/xlib/gvdevice_xlib.c.orig	2014-04-13 20:40:25.000000000 +0000
+++ plugin/xlib/gvdevice_xlib.c
@@ -39,6 +39,9 @@
 #endif
 #ifdef HAVE_SYS_INOTIFY_H
 #include <sys/inotify.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #endif
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
