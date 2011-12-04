$NetBSD: patch-plugins_sound_oss_sound_oss.h,v 1.1 2011/12/04 21:59:37 marino Exp $

--- plugins/sound_oss/sound_oss.h.orig	2009-09-21 00:25:31.000000000 +0000
+++ plugins/sound_oss/sound_oss.h
@@ -15,6 +15,10 @@
 #include <sys/soundcard.h>
 #endif
 
+#ifdef P_DRAGONFLY
+#include <sys/soundcard.h>
+#endif
+
 #ifdef P_FREEBSD
 #if P_FREEBSD >= 500000
 #include <sys/soundcard.h>
