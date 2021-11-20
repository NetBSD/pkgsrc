$NetBSD: patch-src_controllers_controllermanager.cpp,v 1.2 2021/11/20 19:07:37 nia Exp $

Support building without PortMIDI.

--- src/controllers/controllermanager.cpp.orig	2021-09-29 13:23:02.000000000 +0000
+++ src/controllers/controllermanager.cpp
@@ -24,7 +24,7 @@
 // http://developer.qt.nokia.com/wiki/Threads_Events_QObjects
 
 // Poll every 1ms (where possible) for good controller response
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__NetBSD__)
 // Many Linux distros ship with the system tick set to 250Hz so 1ms timer
 // reportedly causes CPU hosage. See Bug #990992 rryan 6/2012
 const mixxx::Duration ControllerManager::kPollInterval = mixxx::Duration::fromMillis(5);
@@ -139,7 +139,9 @@ void ControllerManager::slotInitialize()
 
     // Instantiate all enumerators. Enumerators can take a long time to
     // construct since they interact with host MIDI APIs.
+#ifdef __PORTMIDI__
     m_enumerators.append(new PortMidiEnumerator(m_pConfig));
+#endif
 #ifdef __HSS1394__
     m_enumerators.append(new Hss1394Enumerator(m_pConfig));
 #endif
