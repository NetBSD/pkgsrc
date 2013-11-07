$NetBSD: patch-libkopete_avdevice_videodevice.h,v 1.1 2013/11/07 13:03:07 markd Exp $

--- libkopete/avdevice/videodevice.h.orig	2011-04-01 10:59:27.000000000 +0000
+++ libkopete/avdevice/videodevice.h
@@ -75,6 +75,13 @@
 #endif // HAVE_V4L2
 
 #endif // __linux__ __FreeBSD__ ENABLE_AV
+#if (defined(__NetBSD__) || defined(__DragonFly__)) && defined(ENABLE_AV)
+
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif // HAVE_V4L2
+
+#endif // __NetBSD__ __DragonFly__
 
 #include <qstring.h>
 #include <qfile.h>
