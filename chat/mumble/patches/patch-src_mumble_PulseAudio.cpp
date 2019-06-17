$NetBSD: patch-src_mumble_PulseAudio.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/PulseAudio.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/PulseAudio.cpp
@@ -37,11 +37,12 @@
 #include <errno.h>
 #include <sys/ioctl.h>
 
-#include "Global.h"
 #include "MainWindow.h"
 #include "Timer.h"
 #include "User.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
 
 static const char *mumble_sink_input = "Mumble Speakers";
 static const char *mumble_echo = "Mumble Speakers (Echo)";
