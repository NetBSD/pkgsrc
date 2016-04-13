$NetBSD: patch-gio_inotify_inotify-kernel.c,v 1.1 2016/04/13 10:13:43 jperkin Exp $

Use _XOPEN_NAME_MAX in lieu of NAME_MAX for SunOS.

--- gio/inotify/inotify-kernel.c.orig	2016-02-23 22:25:36.000000000 +0000
+++ gio/inotify/inotify-kernel.c
@@ -36,6 +36,9 @@
 #include "glib-private.h"
 
 /* From inotify(7) */
+#if !defined(NAME_MAX) && defined(_XOPEN_NAME_MAX)
+#define NAME_MAX             _XOPEN_NAME_MAX
+#endif
 #define MAX_EVENT_SIZE       (sizeof(struct inotify_event) + NAME_MAX + 1)
 
 /* Amount of time to sleep on receipt of uninteresting events */
