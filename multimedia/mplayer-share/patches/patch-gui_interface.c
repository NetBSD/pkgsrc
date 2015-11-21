$NetBSD: patch-gui_interface.c,v 1.3 2015/11/21 09:47:23 leot Exp $

Add missing global variable to avoid link error.

If DVD support is compiled in, dvd_angle is provided by stream_dvd.c
instead.

--- gui/interface.c.orig	2015-09-08 21:02:40.000000000 +0000
+++ gui/interface.c
@@ -61,6 +61,8 @@
 #include "stream/stream.h"
 #ifdef CONFIG_DVDREAD
 #include "stream/stream_dvd.h"
+#else
+int dvd_angle = 1;
 #endif
 #include "sub/font_load.h"
 #include "sub/sub.h"
