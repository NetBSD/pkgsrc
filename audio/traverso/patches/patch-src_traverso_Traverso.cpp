$NetBSD: patch-src_traverso_Traverso.cpp,v 1.1 2020/04/24 08:43:08 nia Exp $

Use Sun on NetBSD and OSS on other unixes.

Pick a nicer default sample rate for NetBSD and SunOS.

--- src/traverso/Traverso.cpp.orig	2017-10-09 20:04:26.000000000 +0000
+++ src/traverso/Traverso.cpp
@@ -306,9 +306,13 @@ void Traverso::setup_fpu()
 
 void Traverso::prepare_audio_device( )
 {
+#if defined (__NetBSD__) || defined (__sun)
+	int rate = config().get_property("Hardware", "samplerate", 48000).toInt();
+#else
 	int rate = config().get_property("Hardware", "samplerate", 44100).toInt();
+#endif
 	int bufferSize = config().get_property("Hardware", "buffersize", 512).toInt();
-#if defined (Q_WS_X11)
+#if defined (__linux__)
 	QString driverType = config().get_property("Hardware", "drivertype", "ALSA").toString();
 #else
 	QString driverType = config().get_property("Hardware", "drivertype", "PortAudio").toString();
@@ -339,12 +343,16 @@ void Traverso::prepare_audio_device( )
 	
 #if defined (PORTAUDIO_SUPPORT)
 	if (driverType == "PortAudio") {
-#if defined (Q_WS_X11)
+#if defined (__linux__)
 		cardDevice = config().get_property("Hardware", "pahostapi", "alsa").toString();
+#elif defined (__NetBSD__)
+		cardDevice = config().get_property("Hardware", "pahostapi", "sun").toString();
 #elif defined (Q_WS_MAC)
 		cardDevice = config().get_property("Hardware", "pahostapi", "coreaudio").toString();
 #elif defined (Q_WS_WIN)
 		cardDevice = config().get_property("Hardware", "pahostapi", "wmme").toString();
+#else
+		cardDevice = config().get_property("Hardware", "pahostapi", "oss").toString();
 #endif
 	}
 #endif // end PORTAUDIO_SUPPORT
