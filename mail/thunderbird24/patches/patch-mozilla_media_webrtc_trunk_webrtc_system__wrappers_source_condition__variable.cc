$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable.cc,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc.orig	2013-10-23 22:09:13.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc
@@ -16,6 +16,8 @@
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <pthread.h>
 #include "condition_variable_posix.h"
+#else
+#include <stddef.h>  // for NULL
 #endif
 
 namespace webrtc {
