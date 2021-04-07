$NetBSD: patch-src_gui_views_ArcBall.h,v 1.1 2021/04/07 12:28:22 markd Exp $

Not finding NULL on NetBSD9

--- src/gui/views/ArcBall.h.orig	2021-02-28 22:44:32.000000000 +0000
+++ src/gui/views/ArcBall.h
@@ -20,6 +20,10 @@
 #ifndef _ArcBall_h
 #define _ArcBall_h
 
+#ifdef __NetBSD__
+#include <sys/null.h>
+#endif
+
 #include "math.h"                                               // Needed for sqrtf
 
 // 8<--Snip here if you have your own math types/funcs-->8 
