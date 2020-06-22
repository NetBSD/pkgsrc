$NetBSD: patch-src_gst_fluidsynth_fluidsynth.h,v 1.1 2020/06/22 11:18:39 nia Exp $

Fix build with fluidsynth 2.x. From Debian.

--- src/gst/fluidsynth/fluidsynth.h.orig	2015-12-29 21:24:20.000000000 +0000
+++ src/gst/fluidsynth/fluidsynth.h
@@ -93,6 +93,7 @@ struct _GstBtFluidSynth {
   fluid_settings_t *settings;       /* to free on close */
   fluid_midi_driver_t *midi;		    /* FluidSynth MIDI driver */
   fluid_midi_router_t *midi_router; /* FluidSynth MIDI router */
+  fluid_cmd_handler_t *cmd_handler;
 
   gchar *instrument_patch_path;
   gint instrument_patch;
