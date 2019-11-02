$NetBSD: patch-src_qsynthOptions.cpp,v 1.2 2019/11/02 15:05:29 nia Exp $

Use OSS as the default audio driver on non-Linux.

--- src/qsynthOptions.cpp.orig	2019-10-17 07:46:21.791671088 +0000
+++ src/qsynthOptions.cpp
@@ -493,9 +493,12 @@ void qsynthOptions::loadSetup ( qsynthSe
 #elif defined(__OpenBSD__)
 	pSetup->sMidiDriver      = m_settings.value("/MidiDriver", "sndio").toString();
 	pSetup->sAudioDriver     = m_settings.value("/AudioDriver", "sndio").toString();
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
