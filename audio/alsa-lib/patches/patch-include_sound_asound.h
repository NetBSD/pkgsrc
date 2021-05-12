$NetBSD: patch-include_sound_asound.h,v 1.6 2021/05/12 14:12:13 ryoon Exp $

--- include/sound/asound.h.orig	2020-06-29 10:51:08.000000000 +0000
+++ include/sound/asound.h
@@ -8,4 +8,5 @@
 #define __kernel_long_t long
 #endif
 
+#include <alsa/sound/type_compat.h>
 #include <alsa/sound/uapi/asound.h>
