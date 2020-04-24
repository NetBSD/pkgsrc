$NetBSD: patch-src_traverso_dialogs_settings_Pages.cpp,v 1.1 2020/04/24 08:43:08 nia Exp $

Support Sun on NetBSD and OSS on other unixes.

--- src/traverso/dialogs/settings/Pages.cpp.orig	2017-10-09 11:40:46.000000000 +0000
+++ src/traverso/dialogs/settings/Pages.cpp
@@ -139,9 +139,15 @@ void AudioDriverConfigPage::reset_defaul
 #endif
 	
 #if defined (PORTAUDIO_SUPPORT)
-#if defined (Q_WS_X11)
+#if defined (__linux__)
 	config().set_property("Hardware", "pahostapi", "alsa");
 #endif
+#if defined (Q_WS_X11)
+	config().set_property("Hardware", "pahostapi", "oss");
+#endif
+#if defined (__NetBSD__)
+	config().set_property("Hardware", "pahostapi", "sun");
+#endif
 #if defined (Q_WS_MAC)
 	config().set_property("Hardware", "pahostapi", "coreaudio");
 #endif
@@ -162,7 +168,7 @@ void AudioDriverConfigPage::load_config(
 {
 	int samplerate = config().get_property("Hardware", "samplerate", 44100).toInt();
 	int buffersize = config().get_property("Hardware", "buffersize", 512).toInt();
-#if defined (Q_WS_X11)
+#if defined (__linux__)
 	QString driverType = config().get_property("Hardware", "drivertype", "ALSA").toString();
 #else
 	QString driverType = config().get_property("Hardware", "drivertype", "PortAudio").toString();
@@ -232,24 +238,21 @@ void AudioDriverConfigPage::load_config(
 	m_portaudiodrivers->driverCombo->clear();
 	QString defaulthostapi = "";
 
-#if defined (Q_WS_X11)
-	m_portaudiodrivers->driverCombo->addItem("ALSA", "alsa");
-	m_portaudiodrivers->driverCombo->addItem("Jack", "jack");
-	m_portaudiodrivers->driverCombo->addItem("OSS", "oss");
-	defaulthostapi = "jack";
-#endif
-
 #if defined (Q_WS_MAC)
 	m_portaudiodrivers->driverCombo->addItem("Core Audio", "coreaudio");
 	m_portaudiodrivers->driverCombo->addItem("Jack", "jack");
 	defaulthostapi = "coreaudio";
-#endif
-
-#if defined (Q_WS_WIN)
+#elif defined (Q_WS_WIN)
 	m_portaudiodrivers->driverCombo->addItem("MME", "wmme");
 	m_portaudiodrivers->driverCombo->addItem("Direct Sound", "directsound");
 	m_portaudiodrivers->driverCombo->addItem("ASIO", "asio");
 	defaulthostapi = "wmme";
+#else
+	m_portaudiodrivers->driverCombo->addItem("ALSA", "alsa");
+	m_portaudiodrivers->driverCombo->addItem("Jack", "jack");
+	m_portaudiodrivers->driverCombo->addItem("OSS", "oss");
+	m_portaudiodrivers->driverCombo->addItem("Sun", "sun");
+	defaulthostapi = "oss";
 #endif
 	
 	QString hostapi = config().get_property("Hardware", "pahostapi", defaulthostapi).toString();
