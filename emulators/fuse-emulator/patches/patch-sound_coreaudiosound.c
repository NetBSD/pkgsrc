$NetBSD: patch-sound_coreaudiosound.c,v 1.1 2017/08/02 10:24:26 adam Exp $

Fix for macOS High Sierra.

--- sound/coreaudiosound.c.orig	2017-08-02 09:46:04.000000000 +0000
+++ sound/coreaudiosound.c
@@ -22,6 +22,7 @@
 #include <errno.h>
 #include <unistd.h>
 
+#define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 1
 #include <AssertMacros.h>
 
 #include <AudioToolbox/AudioToolbox.h>
