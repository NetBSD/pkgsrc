$NetBSD: patch-akode_plugins_sun__sink_sun__sink.cpp,v 1.1 2012/02/15 19:33:26 hans Exp $

--- akode/plugins/sun_sink/sun_sink.cpp.orig	2012-01-12 19:07:47.881281153 +0100
+++ akode/plugins/sun_sink/sun_sink.cpp	2012-01-12 19:20:50.139729686 +0100
@@ -30,6 +30,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include <audioframe.h>
 #include "sun_sink.h"
 
