$NetBSD: patch-mpeglib_lib_util_audio_audioIO__SunOS.cpp,v 1.1 2014/07/10 17:00:21 jperkin Exp $

Fix include name.

--- mpeglib/lib/util/audio/audioIO_SunOS.cpp.orig	2005-09-10 08:19:53.000000000 +0000
+++ mpeglib/lib/util/audio/audioIO_SunOS.cpp
@@ -14,7 +14,7 @@
 #include <stdio.h>
 #include <sys/audioio.h>
 #include "audioIO.h"
-#include <iostream.h>
+#include <iostream>
 
 /* declare these static to effectively isolate the audio device */
 
