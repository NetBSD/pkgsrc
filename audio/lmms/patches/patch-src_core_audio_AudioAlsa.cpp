$NetBSD: patch-src_core_audio_AudioAlsa.cpp,v 1.1 2013/06/17 15:16:47 ryoon Exp $

* Define ESTRPIPE for NetBSD at least.

--- src/core/audio/AudioAlsa.cpp.orig	2013-06-11 20:57:16.000000000 +0000
+++ src/core/audio/AudioAlsa.cpp
@@ -36,7 +36,9 @@
 #include "gui_templates.h"
 #include "templates.h"
 
-
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
 
 AudioAlsa::AudioAlsa( bool & _success_ful, mixer * _mixer ) :
 	AudioDevice( tLimit<ch_cnt_t>(
