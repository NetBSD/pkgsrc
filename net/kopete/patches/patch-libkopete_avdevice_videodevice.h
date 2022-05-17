$NetBSD: patch-libkopete_avdevice_videodevice.h,v 1.2 2022/05/17 13:35:47 jperkin Exp $

--- libkopete/avdevice/videodevice.h.orig	2016-12-13 01:23:22.000000000 +0000
+++ libkopete/avdevice/videodevice.h
@@ -73,6 +73,13 @@
 #endif // HAVE_V4L2
 
 #endif // __linux__ __FreeBSD__ ENABLE_AV
+#if (defined(__NetBSD__) || defined(__DragonFly__) || defined(__sun)) && defined(ENABLE_AV)
+
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif // HAVE_V4L2
+
+#endif // __NetBSD__ __DragonFly__
 
 #include <qstring.h>
 #include <qfile.h>
