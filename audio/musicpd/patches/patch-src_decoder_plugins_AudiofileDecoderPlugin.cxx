$NetBSD: patch-src_decoder_plugins_AudiofileDecoderPlugin.cxx,v 1.1 2019/01/15 10:04:53 wiz Exp $

../src/decoder/plugins/AudiofileDecoderPlugin.cxx:131:39: error: use of undeclared identifier 'malloc'; did you mean 'tzalloc'?
https://github.com/MusicPlayerDaemon/MPD/issues/456

--- src/decoder/plugins/AudiofileDecoderPlugin.cxx.orig	2019-01-04 18:22:21.000000000 +0000
+++ src/decoder/plugins/AudiofileDecoderPlugin.cxx
@@ -33,6 +33,7 @@
 
 #include <assert.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 static constexpr Domain audiofile_domain("audiofile");
 
