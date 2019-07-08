$NetBSD: patch-src_controllers_controllermanager.cpp,v 1.1 2019/07/08 16:46:32 nia Exp $

Support building without PortMIDI.

--- src/controllers/controllermanager.cpp.orig	2019-04-22 07:50:04.000000000 +0000
+++ src/controllers/controllermanager.cpp
@@ -127,7 +127,9 @@ void ControllerManager::slotInitialize()
 
     // Instantiate all enumerators. Enumerators can take a long time to
     // construct since they interact with host MIDI APIs.
+#ifdef __PORTMIDI__
     m_enumerators.append(new PortMidiEnumerator());
+#endif
 #ifdef __HSS1394__
     m_enumerators.append(new Hss1394Enumerator());
 #endif
