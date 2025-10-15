$NetBSD: patch-src_framework_midi_midimodule.h,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/framework/midi/midimodule.h.orig	2025-07-21 11:39:02.159714515 +0000
+++ src/framework/midi/midimodule.h
@@ -34,6 +34,9 @@ class AlsaMidiInPort;
 #elif defined(Q_OS_FREEBSD)
 class AlsaMidiOutPort;
 class AlsaMidiInPort;
+#elif defined(Q_OS_NETBSD)
+class AlsaMidiOutPort;
+class AlsaMidiInPort;
 #elif defined(Q_OS_WIN)
 class WinMidiOutPort;
 class WinMidiInPort;
@@ -57,7 +60,7 @@ public:
 private:
     std::shared_ptr<MidiConfiguration> m_configuration;
 
-    #if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+    #if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     std::shared_ptr<AlsaMidiOutPort> m_midiOutPort;
     std::shared_ptr<AlsaMidiInPort> m_midiInPort;
 
