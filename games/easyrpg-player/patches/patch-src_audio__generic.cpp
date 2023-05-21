$NetBSD: patch-src_audio__generic.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/audio_generic.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/audio_generic.cpp
@@ -167,7 +167,7 @@ void GenericAudio::SE_Play(Filesystem_St
 		}
 	}
 	// FIXME Not displaying as warning because multiple games exhaust free channels available, see #1356
-	Output::Debug("Couldn't play {} SE. No free channel available", stream.GetName());
+	Output::Debug("Couldn't play {} SE. No free channel available", std::string(stream.GetName()));
 }
 
 void GenericAudio::SE_Stop() {
@@ -191,7 +191,7 @@ bool GenericAudio::PlayOnChannel(BgmChan
 	chan.stopped = false; // Unstop channel so the audio thread doesn't delete it
 
 	if (!filestream) {
-		Output::Warning("BGM file not readable: {}", filestream.GetName());
+		Output::Warning("BGM file not readable: {}", std::string(filestream.GetName()));
 		return false;
 	}
 
@@ -247,7 +247,7 @@ bool GenericAudio::PlayOnChannel(BgmChan
 
 		return true;
 	} else {
-		Output::Warning("Couldn't play BGM {}. Format not supported", filestream.GetName());
+		Output::Warning("Couldn't play BGM {}. Format not supported", std::string(filestream.GetName()));
 	}
 
 	return false;
@@ -266,7 +266,7 @@ bool GenericAudio::PlayOnChannel(SeChann
 		chan.paused = false; // Unpause channel -> Play it.
 		return true;
 	} else {
-		Output::Warning("Couldn't play SE {}. Format not supported", filestream.GetName());
+		Output::Warning("Couldn't play SE {}. Format not supported", std::string(filestream.GetName()));
 	}
 
 	return false;
