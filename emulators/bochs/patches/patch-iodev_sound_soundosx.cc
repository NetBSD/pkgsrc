$NetBSD: patch-iodev_sound_soundosx.cc,v 1.3 2024/02/11 23:30:40 ryoon Exp $

--- iodev/sound/soundosx.cc.orig	2021-03-11 21:46:25.040844000 +0000
+++ iodev/sound/soundosx.cc
@@ -26,7 +26,7 @@
 #define BX_PLUGGABLE
 
 #ifdef PARANOID
-#include <MacTypes.h>
+#include <CoreServices/CoreServices.h>
 #endif
 
 #include "bochs.h"
