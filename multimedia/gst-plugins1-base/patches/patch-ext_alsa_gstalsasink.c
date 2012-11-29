$NetBSD: patch-ext_alsa_gstalsasink.c,v 1.1 2012/11/29 08:22:29 ryoon Exp $

* NetBSD has no ESTRPIPE

--- ext/alsa/gstalsasink.c.orig	2012-09-19 14:07:16.000000000 +0000
+++ ext/alsa/gstalsasink.c
@@ -54,6 +54,10 @@
 #include <gst/audio/gstaudioiec61937.h>
 #include <gst/gst-i18n-plugin.h>
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 #define DEFAULT_DEVICE		"default"
 #define DEFAULT_DEVICE_NAME	""
 #define DEFAULT_CARD_NAME	""
