$NetBSD: patch-src_qsynthOptions.cpp,v 1.1 2019/10/17 08:20:43 nia Exp $

Use OSS as the default audio driver on non-Linux/macOS.

--- src/qsynthOptions.cpp.orig	2019-07-12 10:35:23.877356128 +0000
+++ src/qsynthOptions.cpp
@@ -487,9 +487,12 @@ void qsynthOptions::loadSetup ( qsynthSe
 #elif defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
 	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "winmidi").toString();
 	pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "dsound").toString();
-#else
+#elif defined(__linux__)
 	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "alsa_seq").toString();
-	pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "jack").toString();
+	pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "alsa").toString();
+#else
+	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "oss").toString();
+	pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "oss").toString();
 #endif
 #if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
 	pSetup->iAudioBufSize    = m_settings.value("/AudioBufSize", 512).toInt();
