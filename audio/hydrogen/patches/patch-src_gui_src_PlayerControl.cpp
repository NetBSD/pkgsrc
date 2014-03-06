$NetBSD: patch-src_gui_src_PlayerControl.cpp,v 1.1 2014/03/06 10:16:15 mrg Exp $

--- src/gui/src/PlayerControl.cpp.orig	2013-02-21 10:53:51.000000000 -0800
+++ src/gui/src/PlayerControl.cpp	2014-03-06 00:47:13.000000000 -0800
@@ -624,7 +624,8 @@
 
 	// time
 	float fFrames = m_pEngine->getAudioOutput()->m_transport.m_nFrames;
-	if ( Preferences::get_instance()->m_bJackTransportMode == Preferences::USE_JACK_TRANSPORT )
+	if ( Preferences::get_instance()->m_bJackTransportMode == Preferences::USE_JACK_TRANSPORT &&
+	     Preferences::get_instance()->m_bJackMasterMode != Preferences::NO_JACK_TIME_MASTER )
 		fFrames =  m_pEngine->getHumantimeFrames();
 	float fSampleRate = m_pEngine->getAudioOutput()->getSampleRate();
 	if ( fSampleRate != 0 ) {
