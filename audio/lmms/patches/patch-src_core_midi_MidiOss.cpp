$NetBSD: patch-src_core_midi_MidiOss.cpp,v 1.1 2019/10/24 16:36:56 nia Exp $

Support NetBSD's OSS emulation.

--- src/core/midi/MidiOss.cpp.orig	2018-11-03 01:43:42.000000000 +0000
+++ src/core/midi/MidiOss.cpp
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
