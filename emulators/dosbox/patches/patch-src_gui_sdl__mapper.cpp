$NetBSD: patch-src_gui_sdl__mapper.cpp,v 1.1 2014/04/17 00:49:51 wiz Exp $

Avoid overrunning array.

--- src/gui/sdl_mapper.cpp.orig	2010-05-10 18:58:06.000000000 +0000
+++ src/gui/sdl_mapper.cpp
@@ -2384,9 +2384,11 @@ void MAPPER_StartUp(Section * sec) {
 	mapper.sticks.num=0;
 	mapper.sticks.num_groups=0;
 	Bitu i;
-	for (i=0; i<16; i++) {
+	for (i=0; i<MAX_VJOY_BUTTONS; i++) {
 		virtual_joysticks[0].button_pressed[i]=false;
 		virtual_joysticks[1].button_pressed[i]=false;
+	}
+	for (i=0; i<16; i++) {
 		virtual_joysticks[0].hat_pressed[i]=false;
 		virtual_joysticks[1].hat_pressed[i]=false;
 	}
