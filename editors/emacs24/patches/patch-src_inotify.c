$NetBSD: patch-src_inotify.c,v 1.1 2015/01/31 23:40:09 jperkin Exp $

SunOS inotify requires sys/filio.h for FIONREAD.

--- src/inotify.c.orig	2014-03-21 05:34:40.000000000 +0000
+++ src/inotify.c
@@ -59,6 +59,9 @@ static Lisp_Object Qunmount;       /* IN
 
 #include <sys/inotify.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 /* Ignore bits that might be undefined on old GNU/Linux systems.  */
 #ifndef IN_EXCL_UNLINK
