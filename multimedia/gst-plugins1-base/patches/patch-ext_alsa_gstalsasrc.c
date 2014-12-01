$NetBSD: patch-ext_alsa_gstalsasrc.c,v 1.2 2014/12/01 08:13:04 wiz Exp $

* NetBSD has no ESTRPIPE
https://bugzilla.gnome.org/show_bug.cgi?id=740952

--- ext/alsa/gstalsasrc.c.orig	2012-09-10 10:08:34.000000000 +0000
+++ ext/alsa/gstalsasrc.c
@@ -51,6 +51,10 @@
 
 #include <gst/gst-i18n-plugin.h>
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 #define DEFAULT_PROP_DEVICE		"default"
 #define DEFAULT_PROP_DEVICE_NAME	""
 #define DEFAULT_PROP_CARD_NAME	        ""
