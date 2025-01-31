$NetBSD: patch-src_audio_ItDecoder.cpp,v 1.1 2025/01/31 08:07:01 wiz Exp $

Make sure to find correct header.

--- src/audio/ItDecoder.cpp.orig	2025-01-31 08:01:28.552555139 +0000
+++ src/audio/ItDecoder.cpp
@@ -17,7 +17,7 @@
 #include "solarus/audio/ItDecoder.h"
 #include "solarus/core/Debug.h"
 #include <stdafx.h>  // These two headers are with the libmodplug ones.
-#include <sndfile.h>
+#include <libmodplug/sndfile.h>
 
 namespace Solarus {
 
