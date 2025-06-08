$NetBSD: patch-Source_Core_AudioCommon_OpenALStream.cpp,v 1.1 2025/06/08 23:54:35 nia Exp $

Make this work on NetBSD.

--- Source/Core/AudioCommon/OpenALStream.cpp.orig	2025-06-08 23:32:45.886303150 +0000
+++ Source/Core/AudioCommon/OpenALStream.cpp
@@ -139,12 +139,20 @@ void OpenALStream::SoundLoop()
 	surround_capable = false;
 	const ALenum AL_FORMAT_51CHN32 = 0;
 	const ALenum AL_FORMAT_51CHN16 = 0;
+#elif defined(__NetBSD__)
+	bool float32_capable = false;
+	surround_capable = false;
 #else
 	bool float32_capable = true;
 #endif
 
 	u32 ulFrequency = m_mixer->GetSampleRate();
+
+#ifndef __NetBSD__
 	numBuffers = SConfig::GetInstance().iLatency + 2; // OpenAL requires a minimum of two buffers
+#else
+	numBuffers = SConfig::GetInstance().iLatency + 8;
+#endif
 
 	memset(uiBuffers, 0, numBuffers * sizeof(ALuint));
 	uiSource = 0;
