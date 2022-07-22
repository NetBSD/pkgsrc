$NetBSD: patch-plugin_xlib_gvdevice__xlib.c,v 1.3 2022/07/22 12:04:46 micha Exp $

SunOS inotify requires sys/filio.h for FIONREAD.

--- plugin/xlib/gvdevice_xlib.c.orig	2020-04-08 07:51:58.000000000 +0000
+++ plugin/xlib/gvdevice_xlib.c
@@ -32,6 +32,9 @@
 #endif
 #ifdef HAVE_SYS_INOTIFY_H
 #include <sys/inotify.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #endif
 #include <errno.h>
 #ifdef HAVE_FCNTL_H
