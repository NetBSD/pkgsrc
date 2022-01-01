$NetBSD: patch-sequencer_src_MidiSetupDlgs.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- sequencer/src/MidiSetupDlgs.c~	1997-10-07 21:28:58.000000000 +0000
+++ sequencer/src/MidiSetupDlgs.c
@@ -91,7 +91,7 @@ Midi_ChangesAllTracksCB(Widget w, XtPoin
 /* ELWindowList ThisWindow = (ELWindowList)a; */
 BEGIN("Midi_ChangesAllTracksCB");
 
-     MenuSelection  = (int)b;
+     MenuSelection  = (int)(intptr_t)b;
 
 END;
 }
