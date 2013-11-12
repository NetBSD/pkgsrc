$NetBSD: patch-mozilla_modules_libpref_src_init_all.js,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/modules/libpref/src/init/all.js.orig	2013-10-23 22:09:14.000000000 +0000
+++ mozilla/modules/libpref/src/init/all.js
@@ -188,7 +188,7 @@ pref("media.webm.enabled", true);
 pref("media.dash.enabled", false);
 #endif
 #ifdef MOZ_GSTREAMER
-pref("media.gstreamer.enabled", false);
+pref("media.gstreamer.enabled", true);
 #endif
 #ifdef MOZ_WEBRTC
 pref("media.navigator.enabled", true);
