$NetBSD: patch-media_webrtc_trunk_webrtc_modules_audio__device_linux_audio__device__alsa__linux.cc,v 1.1 2018/12/16 08:12:16 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/audio_device/linux/audio_device_alsa_linux.cc.orig	2018-12-04 23:11:54.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/audio_device/linux/audio_device_alsa_linux.cc
@@ -60,6 +60,10 @@ static const unsigned int ALSA_CAPTURE_W
 #define FUNC_GET_DEVICE_NAME 1
 #define FUNC_GET_DEVICE_NAME_FOR_AN_ENUM 2
 
+#if !defined(ESTRPIPE)
+#define ESTRPIPE EPIPE
+#endif
+
 AudioDeviceLinuxALSA::AudioDeviceLinuxALSA(const int32_t id) :
     _ptrAudioBuffer(NULL),
     _critSect(*CriticalSectionWrapper::CreateCriticalSection()),
