$NetBSD: patch-gio_inotify_inotify-kernel.c,v 1.3 2019/06/03 23:09:29 maya Exp $

Use _XOPEN_NAME_MAX in lieu of NAME_MAX for SunOS.

Include <sys/filio.h> for FIONREAD on SunOS.
https://gitlab.gnome.org/GNOME/glib/merge_requests/889

--- gio/inotify/inotify-kernel.c.orig	2016-02-23 22:25:36.000000000 +0000
+++ gio/inotify/inotify-kernel.c
@@ -30,11 +30,15 @@
 #include <glib.h>
 #include "inotify-kernel.h"
 #include <sys/inotify.h>
+#include <sys/filio.h>
 #include <glib/glib-unix.h>
 
 #include "glib-private.h"
 
 /* From inotify(7) */
+#if !defined(NAME_MAX) && defined(_XOPEN_NAME_MAX)
+#define NAME_MAX             _XOPEN_NAME_MAX
+#endif
 #define MAX_EVENT_SIZE       (sizeof(struct inotify_event) + NAME_MAX + 1)
 
 /* Amount of time to sleep on receipt of uninteresting events */
