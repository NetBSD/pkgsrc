$NetBSD: patch-smbd_notify__inotify.c,v 1.1 2015/02/02 10:42:18 jperkin Exp $

SunOS inotify requires sys/filio.h for FIONREAD.

--- smbd/notify_inotify.c.orig	2014-06-23 06:03:27.000000000 +0000
+++ smbd/notify_inotify.c
@@ -29,6 +29,9 @@
 
 #if HAVE_SYS_INOTIFY_H
 #include <sys/inotify.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #else
 
 #ifdef HAVE_ASM_TYPES_H
