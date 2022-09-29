$NetBSD: patch-src_gui_views_ArcBall.h,v 1.2 2022/09/29 00:47:31 markd Exp $

Not finding NULL on NetBSD9

--- src/gui/views/ArcBall.h.orig	2022-08-17 10:30:44.000000000 +0000
+++ src/gui/views/ArcBall.h
@@ -34,6 +34,10 @@
 #include <GL/glu.h>                                                                                            // Header File For The GLu32 Library
 #endif
 
+#ifdef __NetBSD__
+#include <sys/null.h>
+#endif
+
 #include <math.h>                                               // Needed for sqrtf
 
 // 8<--Snip here if you have your own math types/funcs-->8 
