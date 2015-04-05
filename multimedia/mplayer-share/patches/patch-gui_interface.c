$NetBSD: patch-gui_interface.c,v 1.2 2015/04/05 08:27:08 dsainty Exp $

Add missing global variable to avoid link error.

If DVD support is compiled in, dvd_angle is provided by stream_dvd.c
instead.

--- gui/interface.c.orig	2012-05-21 20:46:25.000000000 +0200
+++ gui/interface.c	2014-10-09 16:10:41.000000000 +0200
@@ -54,6 +54,8 @@
 
 #ifdef CONFIG_DVDREAD
 #include "stream/stream_dvd.h"
+#else
+int dvd_angle = 1;
 #endif
 
 guiInterface_t guiInfo = {
