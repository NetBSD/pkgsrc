$NetBSD: patch-src_modules_oss_module-oss.c,v 1.3 2021/02/20 22:10:39 ryoon Exp $

Set DEVOSSAUDIO value to fix default device on NetBSD at least.

--- src/modules/oss/module-oss.c.orig	2021-01-16 17:26:36.000000000 +0000
+++ src/modules/oss/module-oss.c
@@ -95,7 +95,7 @@ PA_MODULE_USAGE(
 PA_MODULE_DEPRECATED("Please use module-alsa-card instead of module-oss!");
 #endif
 
-#define DEFAULT_DEVICE "/dev/dsp"
+#define DEFAULT_DEVICE "@DEVOSSAUDIO@"
 
 struct userdata {
     pa_core *core;
