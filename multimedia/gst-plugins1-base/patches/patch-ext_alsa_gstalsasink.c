$NetBSD: patch-ext_alsa_gstalsasink.c,v 1.2 2014/12/01 08:13:04 wiz Exp $

* NetBSD has no ESTRPIPE
https://bugzilla.gnome.org/show_bug.cgi?id=740952

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
