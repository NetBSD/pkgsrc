$NetBSD: patch-src_core_midi_MidiOss.cpp,v 1.2 2022/01/14 10:59:32 nia Exp $

Support NetBSD's OSS emulation.

--- src/core/midi/MidiOss.cpp.orig	2018-11-03 01:43:42.000000000 +0000
+++ src/core/midi/MidiOss.cpp
@@ -39,8 +39,8 @@ MidiOss::MidiOss() :
 {
 	// only start thread, if opening of MIDI-device is successful,
 	// otherwise isRunning()==false indicates error
-	if( m_midiDev.open( QIODevice::ReadWrite ) ||
-					m_midiDev.open( QIODevice::ReadOnly ) )
+	if( m_midiDev.open( QIODevice::ReadWrite | QIODevice::Unbuffered | QIODevice::ExistingOnly ) ||
+					m_midiDev.open( QIODevice::ReadOnly | QIODevice::Unbuffered | QIODevice::ExistingOnly) )
 	{
 		start( QThread::LowPriority );
 	}
@@ -71,7 +71,11 @@ QString MidiOss::probeDevice()
 		{
 			return getenv( "MIDIDEV" );
 		}
+#ifdef __NetBSD__
+		return "/dev/rmidi0";
+#else
 		return "/dev/midi";
+#endif
 	}
 	return dev;
 }
