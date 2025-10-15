$NetBSD: patch-src_framework_audio_main_internal_audiodrivercontroller.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD, except, without PipeWire.

--- src/framework/audio/main/internal/audiodrivercontroller.cpp.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/framework/audio/main/internal/audiodrivercontroller.cpp
@@ -26,7 +26,7 @@
 #include "audio/driver/platform/jack/jackaudiodriver.h"
 #endif
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include <QtEnvironmentVariables>
 #include "audio/driver/platform/lin/alsaaudiodriver.h"
 #ifdef MUSE_PIPEWIRE_AUDIO_DRIVER
@@ -52,7 +52,7 @@
 
 using namespace muse::audio;
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 static std::shared_ptr<IAudioDriver> makeLinuxAudioDriver(const std::string& driverName)
 {
 #if defined(MUSE_PIPEWIRE_AUDIO_DRIVER)
@@ -68,7 +68,7 @@ static std::shared_ptr<IAudioDriver> mak
     return std::make_shared<AlsaAudioDriver>();
 }
 
-#endif // Q_OS_LINUX || Q_OS_FREEBSD
+#endif // Q_OS_LINUX || Q_OS_FREEBSD || Q_OS_NETBSD
 
 void AudioDriverController::init()
 {
@@ -76,7 +76,7 @@ void AudioDriverController::init()
     m_audioDriver = std::shared_ptr<IAudioDriver>(new JackAudioDriver());
 #else
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     std::string name = configuration()->currentAudioApi();
     m_audioDriver = makeLinuxAudioDriver(name);
 #endif
@@ -115,10 +115,12 @@ muse::async::Notification AudioDriverCon
 
 std::vector<std::string> AudioDriverController::availableAudioApiList() const
 {
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     std::vector<std::string> names {
         "ALSA Audio",
+#if defined(MUSE_PIPEWIRE_AUDIO_DRIVER)
         "PipeWire",
+#endif
     };
 
     return names;
