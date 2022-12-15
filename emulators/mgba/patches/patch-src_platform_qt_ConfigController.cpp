$NetBSD: patch-src_platform_qt_ConfigController.cpp,v 1.1 2022/12/15 11:31:44 nia Exp $

Use a likely "device native" sample rate on SunOS and NetBSD to avoid
expensive in-kernel resampling.

The default audioBuffers seems to cause performance problems in Qt.
Using a reasonable power of two causes "less".

--- src/platform/qt/ConfigController.cpp.orig	2022-10-12 03:30:00.000000000 +0000
+++ src/platform/qt/ConfigController.cpp
@@ -119,8 +119,13 @@ ConfigController::ConfigController(QObje
 	m_opts.audioSync = CoreController::AUDIO_SYNC;
 	m_opts.videoSync = CoreController::VIDEO_SYNC;
 	m_opts.fpsTarget = 60;
+#if defined(__NetBSD__) || defined(__sun)
+	m_opts.audioBuffers = 2048;
+	m_opts.sampleRate = 48000;
+#else
 	m_opts.audioBuffers = 1536;
 	m_opts.sampleRate = 44100;
+#endif
 	m_opts.volume = 0x100;
 	m_opts.logLevel = mLOG_WARN | mLOG_ERROR | mLOG_FATAL;
 	m_opts.rewindEnable = false;
