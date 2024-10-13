$NetBSD: patch-prf_player.cpp,v 1.1 2024/10/13 20:56:41 yhardy Exp $

Enable the OPL3 emulation for adlib music.
The MT32 driver needs munt, so disable it.

--- prf_player.cpp.orig	2024-10-12 22:26:15.279342221 +0000
+++ prf_player.cpp
@@ -21,7 +21,7 @@ static const struct {
 } _midiDrivers[] = {
 #ifdef USE_MIDI_DRIVER
 	{ MODE_ADLIB, TIMER_ADLIB_HZ, &midi_driver_adlib },
-	{ MODE_MT32, TIMER_MT32_HZ, &midi_driver_mt32 },
+//	{ MODE_MT32, TIMER_MT32_HZ, &midi_driver_mt32 },
 #endif
 	{ -1, 0, 0 }
 };
