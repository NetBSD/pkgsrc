$NetBSD: patch-src_decoder_audiofile__decoder__plugin.c,v 1.3 2013/05/26 18:37:39 wiz Exp $

Include unistd.h for SEEK_CUR, SEEK_SET.

--- src/decoder/audiofile_decoder_plugin.c.orig	2012-06-28 00:46:58.000000000 +0900
+++ src/decoder/audiofile_decoder_plugin.c
@@ -27,6 +27,7 @@
 #include <assert.h>
 #include <glib.h>
 #include <stdio.h>
+#include <unistd.h>
 
 #undef G_LOG_DOMAIN
 #define G_LOG_DOMAIN "audiofile"
