$NetBSD: patch-src_engine_PADriver.h,v 1.1 2020/04/24 08:43:08 nia Exp $

Correct portaudio header path for pkgsrc.

--- src/engine/PADriver.h.orig	2009-03-28 08:48:39.000000000 +0000
+++ src/engine/PADriver.h
@@ -23,7 +23,7 @@
 #define PORTAUDIO_DRIVER_H
 
 #include "Driver.h"
-#include "portaudio.h"
+#include <portaudio2/portaudio.h>
 
 class PADriver : public Driver
 {
