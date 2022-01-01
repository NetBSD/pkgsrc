$NetBSD: patch-sequencer_src_EventListWindow.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- sequencer/src/EventListWindow.c~	1997-06-14 15:17:36.000000000 +0000
+++ sequencer/src/EventListWindow.c
@@ -284,7 +284,7 @@ void
 Midi_DeviceMenuCB(Widget w, XtPointer a, XtPointer b)
 {
   ELWindowList ThisWindow = (ELWindowList)a;
-  int i = (int)b;
+  int i = (int)(intptr_t)b;
 
   BEGIN("Midi_DeviceMenuCB");
 
