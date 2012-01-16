$NetBSD: patch-src_decoder_audiofile__decoder__plugin.c,v 1.2 2012/01/16 20:57:32 drochner Exp $

Include unistd.h for SEEK_CUR, SEEK_SET.

--- src/decoder/audiofile_decoder_plugin.c.orig	2011-12-01 13:44:01.000000000 +0000
+++ src/decoder/audiofile_decoder_plugin.c
@@ -26,6 +26,7 @@
 #include <assert.h>
 #include <glib.h>
 #include <stdio.h>
+#include <unistd.h>
 
 #undef G_LOG_DOMAIN
 #define G_LOG_DOMAIN "audiofile"
