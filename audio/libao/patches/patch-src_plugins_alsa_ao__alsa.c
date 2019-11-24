$NetBSD: patch-src_plugins_alsa_ao__alsa.c,v 1.1 2019/11/24 00:35:56 nia Exp $

Allow building on non-Linux.

--- src/plugins/alsa/ao_alsa.c.orig	2016-11-14 08:03:30.000000000 +0000
+++ src/plugins/alsa/ao_alsa.c
@@ -39,6 +39,10 @@
 #include <alsa/asoundlib.h>
 #include <ao/ao.h>
 #include <ao/plugin.h>
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 
 /* default 20 millisecond buffer */
 #define AO_ALSA_BUFFER_TIME 20000
