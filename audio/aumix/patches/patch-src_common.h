$NetBSD: patch-src_common.h,v 1.1 2012/02/15 20:04:30 hans Exp $

--- src/common.h.orig	2002-10-29 22:27:51.000000000 +0100
+++ src/common.h	2012-01-15 20:21:18.171640932 +0100
@@ -42,6 +42,10 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
+#ifdef HAVE_LIMITS_H
+#include <limits.h>
+#endif
+
 #ifdef HAVE_SYS_SOUNDCARD_H
 #include <sys/soundcard.h>
 #else
