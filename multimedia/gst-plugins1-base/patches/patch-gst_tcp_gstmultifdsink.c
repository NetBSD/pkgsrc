$NetBSD: patch-gst_tcp_gstmultifdsink.c,v 1.1 2021/11/18 20:25:45 nia Exp $

PR pkg/56509 gstreamer1 build issues on Solaris (and SmartOS) after
upgrade to 1.18.5

--- gst/tcp/gstmultifdsink.c.orig	2021-09-08 19:02:22.195757900 +0000
+++ gst/tcp/gstmultifdsink.c
@@ -121,6 +121,10 @@
 
 #include "gstmultifdsink.h"
 
+#if !defined(FIONREAD) && defined(__sun)
+#include <sys/filio.h>
+#endif
+
 #define NOT_IMPLEMENTED 0
 
 GST_DEBUG_CATEGORY_STATIC (multifdsink_debug);
