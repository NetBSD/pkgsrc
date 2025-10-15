$NetBSD: patch-src_framework_midi_midimodule.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/framework/midi/midimodule.cpp.orig	2025-07-21 11:39:44.776322345 +0000
+++ src/framework/midi/midimodule.cpp
@@ -34,7 +34,7 @@
 
 using namespace muse::midi;
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include "internal/platform/lin/alsamidioutport.h"
 #include "internal/platform/lin/alsamidiinport.h"
 #elif defined(Q_OS_WIN)
@@ -57,7 +57,7 @@ void MidiModule::registerExports()
 {
     m_configuration = std::make_shared<MidiConfiguration>();
 
-    #if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+    #if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     m_midiOutPort = std::make_shared<AlsaMidiOutPort>();
     m_midiInPort = std::make_shared<AlsaMidiInPort>();
     #elif defined(Q_OS_WIN)
