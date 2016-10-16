$NetBSD: patch-audio_midi__drivers_forked__player.cc,v 1.1 2016/10/16 17:10:49 bsiegert Exp $

--- audio/midi_drivers/forked_player.cc.orig	2009-04-21 03:04:37.000000000 +0000
+++ audio/midi_drivers/forked_player.cc
@@ -41,7 +41,11 @@ const MidiDriver::MidiDriverDesc forked_
 // NB: This function doesn't return unless execlp fails!
 static  void    playFJmidifile(const char *name)
 {
+#ifdef __NetBSD__
+	execlp("midiplay","midiplay","-v","-v",name,(char *)0);
+#else
 	execlp("playmidi","playmidi","-v","-v","-e",name,(char *)0);
+#endif
 }
 
 forked_player::forked_player() : repeat_(false), forked_job(-1)
