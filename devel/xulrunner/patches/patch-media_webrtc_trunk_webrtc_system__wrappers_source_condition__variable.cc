$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_condition__variable.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/condition_variable.cc
@@ -8,14 +8,16 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
+#include "condition_variable_wrapper.h"
+
 #if defined(_WIN32)
 #include <windows.h>
 #include "condition_variable_win.h"
-#include "condition_variable_wrapper.h"
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <pthread.h>
 #include "condition_variable_posix.h"
-#include "condition_variable_wrapper.h"
+#else
+#include <stddef.h>  // for NULL
 #endif
 
 namespace webrtc {
@@ -23,7 +25,7 @@ namespace webrtc {
 ConditionVariableWrapper* ConditionVariableWrapper::CreateConditionVariable() {
 #if defined(_WIN32)
   return new ConditionVariableWindows;
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   return ConditionVariablePosix::Create();
 #else
   return NULL;
