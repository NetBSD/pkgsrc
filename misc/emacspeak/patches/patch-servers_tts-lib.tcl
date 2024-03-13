$NetBSD: patch-servers_tts-lib.tcl,v 1.1 2024/03/13 05:48:36 wiz Exp $

* Use first EMACSPEAK_PLAY if set.

--- servers/tts-lib.tcl.orig	2024-01-29 07:35:28.692559948 +0000
+++ servers/tts-lib.tcl
@@ -356,17 +356,19 @@ proc tts_initialize {} {
     set tts(punctuations) some
     set queue(-1) ""
     set backup(-1) ""
+
     #play program
-    
-    if { [info exists ::env(PULSE_SERVER)] || [file exists /usr/bin/paplay]} {
-    set tts(play) "/usr/bin/paplay"
-} else {
-    set tts(play) "/usr/bin/aplay -q"
-}
     #if env variable EMACSPEAK_PLAY is set, use it;
     if {[info exists env(EMACSPEAK_PLAY)] } {
         set tts(play)  $env(EMACSPEAK_PLAY)
-    } 
+    } else {
+        if { [info exists ::env(PULSE_SERVER)] || [file exists /usr/bin/paplay]} {
+	    set tts(play) "/usr/bin/paplay"
+	} else {
+	    set tts(play) "/usr/bin/aplay -q"
+	}
+    }
+
     #optional debuggin output
     if {[info exists env(DTK_DEBUG)] } {
         set tts(debug) 1
