$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__device_audio__device__impl.cc,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_device/audio_device_impl.cc.orig	2013-10-23 22:09:12.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_device/audio_device_impl.cc
@@ -16,7 +16,9 @@
 #include <assert.h>
 #include <string.h>
 
-#if defined(_WIN32)
+#if defined(WEBRTC_DUMMY_AUDIO_BUILD)
+// do not include platform specific headers
+#elif defined(_WIN32)
     #include "audio_device_utility_win.h"
     #include "audio_device_wave_win.h"
  #if defined(WEBRTC_WINDOWS_CORE_AUDIO_BUILD)
@@ -32,14 +34,8 @@
     #include <stdlib.h>
     #include "audio_device_utility_android.h"
     #include "audio_device_jni_android.h"
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
     #include "audio_device_utility_linux.h"
- #if defined(LINUX_ALSA)
-    #include "audio_device_alsa_linux.h"
- #endif
- #if defined(LINUX_PULSE)
-    #include "audio_device_pulse_linux.h"
- #endif
 #elif defined(WEBRTC_IOS)
     #include "audio_device_utility_ios.h"
     #include "audio_device_ios.h"
@@ -47,6 +43,12 @@
     #include "audio_device_utility_mac.h"
     #include "audio_device_mac.h"
 #endif
+#if defined(LINUX_ALSA)
+    #include "audio_device_alsa_linux.h"
+#endif
+#if defined(LINUX_PULSE)
+    #include "audio_device_pulse_linux.h"
+#endif
 #include "audio_device_dummy.h"
 #include "audio_device_utility_dummy.h"
 #include "critical_section_wrapper.h"
@@ -161,7 +163,7 @@ WebRtc_Word32 AudioDeviceModuleImpl::Che
 #elif defined(WEBRTC_ANDROID)
     platform = kPlatformAndroid;
     WEBRTC_TRACE(kTraceInfo, kTraceAudioDevice, _id, "current platform is ANDROID");
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
     platform = kPlatformLinux;
     WEBRTC_TRACE(kTraceInfo, kTraceAudioDevice, _id, "current platform is LINUX");
 #elif defined(WEBRTC_IOS)
@@ -301,7 +303,7 @@ WebRtc_Word32 AudioDeviceModuleImpl::Cre
 
     // Create the *Linux* implementation of the Audio Device
     //
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
     if ((audioLayer == kLinuxPulseAudio) || (audioLayer == kPlatformDefaultAudio))
     {
 #if defined(LINUX_PULSE)
@@ -347,7 +349,7 @@ WebRtc_Word32 AudioDeviceModuleImpl::Cre
         //
         ptrAudioDeviceUtility = new AudioDeviceUtilityLinux(Id());
     }
-#endif  // #if defined(WEBRTC_LINUX)
+#endif  // #if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 
     // Create the *iPhone* implementation of the Audio Device
     //
