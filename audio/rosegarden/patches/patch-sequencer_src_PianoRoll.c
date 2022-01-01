$NetBSD: patch-sequencer_src_PianoRoll.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- sequencer/src/PianoRoll.c~	1997-05-18 11:57:17.000000000 +0000
+++ sequencer/src/PianoRoll.c
@@ -414,7 +414,7 @@ BEGIN("Midi_PianoRollScrollbarScrollCB")
 
     Zoom = ParentWindow->Zoom;
     if (!ParentWindow) END;
-    Pos = (int)CBdata;
+    Pos = (int)(intptr_t)CBdata;
 
     YGetValue(ParentWindow->Scrollbar, XtNlength, &Length);
 
