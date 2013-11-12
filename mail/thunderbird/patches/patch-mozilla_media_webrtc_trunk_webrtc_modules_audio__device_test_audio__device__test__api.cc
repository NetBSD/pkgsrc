$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__device_test_audio__device__test__api.cc,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_device/test/audio_device_test_api.cc.orig	2013-10-23 22:09:12.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_device/test/audio_device_test_api.cc
@@ -196,7 +196,7 @@ class AudioDeviceAPITest: public testing
     // Create default implementation instance
     EXPECT_TRUE((audio_device_ = AudioDeviceModuleImpl::Create(
                 kId, AudioDeviceModule::kPlatformDefaultAudio)) != NULL);
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
     EXPECT_TRUE((audio_device_ = AudioDeviceModuleImpl::Create(
                 kId, AudioDeviceModule::kWindowsWaveAudio)) == NULL);
     EXPECT_TRUE((audio_device_ = AudioDeviceModuleImpl::Create(
@@ -1689,7 +1689,7 @@ TEST_F(AudioDeviceAPITest, CPULoad) {
 
 // TODO(kjellander): Fix flakiness causing failures on Windows.
 // TODO(phoglund):  Fix flakiness causing failures on Linux.
-#if !defined(_WIN32) && !defined(WEBRTC_LINUX)
+#if !defined(_WIN32) && !defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 TEST_F(AudioDeviceAPITest, StartAndStopRawOutputFileRecording) {
   // NOTE: this API is better tested in a functional test
   CheckInitialPlayoutStates();
@@ -1758,7 +1758,7 @@ TEST_F(AudioDeviceAPITest, StartAndStopR
   // - size of raw_input_not_recording.pcm shall be 0
   // - size of raw_input_not_recording.pcm shall be > 0
 }
-#endif  // !WIN32 && !WEBRTC_LINUX
+#endif  // !WIN32 && !WEBRTC_LINUX && !defined(WEBRTC_BSD)
 
 TEST_F(AudioDeviceAPITest, RecordingSampleRate) {
   WebRtc_UWord32 sampleRate(0);
