$NetBSD: patch-src_gst_fluidsynth_fluidsynth.c,v 1.1 2020/06/22 11:18:39 nia Exp $

Fix build with fluidsynth 2.x. From Debian.

--- src/gst/fluidsynth/fluidsynth.c.orig	2015-12-29 21:24:20.000000000 +0000
+++ src/gst/fluidsynth/fluidsynth.c
@@ -132,25 +132,41 @@ G_DEFINE_TYPE (GstBtFluidSynth, gstbt_fl
 //-- fluid_synth log handler
 
 static void
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 gstbt_fluid_synth_error_log_function (int level, char *message, void *data)
+#else
+gstbt_fluid_synth_error_log_function (int level, const char *message, void *data)
+#endif
 {
   GST_ERROR ("%s", message);
 }
 
 static void
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 gstbt_fluid_synth_warning_log_function (int level, char *message, void *data)
+#else
+gstbt_fluid_synth_warning_log_function (int level, const char *message, void *data)
+#endif
 {
   GST_WARNING ("%s", message);
 }
 
 static void
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 gstbt_fluid_synth_info_log_function (int level, char *message, void *data)
+#else
+gstbt_fluid_synth_info_log_function (int level, const char *message, void *data)
+#endif
 {
   GST_INFO ("%s", message);
 }
 
 static void
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 gstbt_fluid_synth_debug_log_function (int level, char *message, void *data)
+#else
+gstbt_fluid_synth_debug_log_function (int level, const char *message, void *data)
+#endif
 {
   GST_DEBUG ("%s", message);
 }
@@ -212,7 +228,11 @@ typedef struct
 
 /* for counting the number of FluidSynth settings properties */
 static void
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 settings_foreach_count (void *data, char *name, int type)
+#else
+settings_foreach_count (void *data, const char *name, int type)
+#endif
 {
   int *count = (int *) data;
   *count = *count + 1;
@@ -220,7 +240,11 @@ settings_foreach_count (void *data, char
 
 /* add each FluidSynth setting as a GObject property */
 static void
+#if FLUIDSYNTH_VERSION_MAJOR < 2
 settings_foreach_func (void *data, char *name, int type)
+#else
+settings_foreach_func (void *data, const char *name, int type)
+#endif
 {
   ForeachBag *bag = (ForeachBag *) data;
   GParamSpec *spec;
@@ -231,18 +255,30 @@ settings_foreach_func (void *data, char 
   switch (type) {
     case FLUID_NUM_TYPE:
       fluid_settings_getnum_range (bag->settings, name, &dmin, &dmax);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
       ddef = fluid_settings_getnum_default (bag->settings, name);
+#else
+      if (fluid_settings_getnum_default (bag->settings, name, &ddef) != FLUID_OK) ddef = 0;
+#endif
       spec = g_param_spec_double (name, name, name, dmin, dmax, ddef,
           G_PARAM_READWRITE);
       break;
     case FLUID_INT_TYPE:
       fluid_settings_getint_range (bag->settings, name, &imin, &imax);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
       idef = fluid_settings_getint_default (bag->settings, name);
+#else
+      if (fluid_settings_getint_default (bag->settings, name, &idef) != FLUID_OK) idef = 0;
+#endif
       spec = g_param_spec_int (name, name, name, imin, imax, idef,
           G_PARAM_READWRITE);
       break;
     case FLUID_STR_TYPE:
-      defstr = fluid_settings_getstr_default (bag->settings, name);
+#if FLUIDSYNTH_VERSION_MAJOR < 2
+      fluid_settings_getstr_default (bag->settings, name);
+#else
+      if (fluid_settings_getstr_default (bag->settings, name,&defstr) != FLUID_OK) defstr = 0;
+#endif
       spec = g_param_spec_string (name, name, name, defstr, G_PARAM_READWRITE);
       break;
     case FLUID_SET_TYPE:
@@ -582,9 +618,9 @@ gstbt_fluid_synth_get_property (GObject 
           g_value_set_double (value, d);
         break;
       case G_TYPE_STRING:
-        retval = fluid_settings_getstr (src->settings, name, &s);
+        retval = fluid_settings_dupstr (src->settings, name, &s);
         if (retval)
-          g_value_set_string (value, s);
+          g_value_take_string (value, s);
         break;
       default:
         g_critical ("Unexpected FluidSynth dynamic property type");
@@ -666,11 +702,14 @@ gstbt_fluid_synth_dispose (GObject * obj
     delete_fluid_midi_driver (gstsynth->midi);
   if (gstsynth->midi_router)
     delete_fluid_midi_router (gstsynth->midi_router);
+  if (gstsynth->cmd_handler)
+    delete_fluid_cmd_handler (gstsynth->cmd_handler);
   if (gstsynth->fluid)
     delete_fluid_synth (gstsynth->fluid);
 
   gstsynth->midi = NULL;
   gstsynth->midi_router = NULL;
+  gstsynth->cmd_handler = NULL;
   gstsynth->fluid = NULL;
 
   g_free (gstsynth->instrument_patch_path);
@@ -714,14 +753,21 @@ gstbt_fluid_synth_init (GstBtFluidSynth 
   /* create MIDI router to send MIDI to FluidSynth */
   src->midi_router =
       new_fluid_midi_router (src->settings,
-      fluid_synth_handle_midi_event, (void *) src);
+      fluid_synth_handle_midi_event, src->fluid);
   if (src->midi_router) {
-    fluid_synth_set_midi_router (src->fluid, src->midi_router);
-    src->midi =
-        new_fluid_midi_driver (src->settings,
-        fluid_midi_router_handle_midi_event, (void *) (src->midi_router));
-    if (!src->midi)
-      g_warning ("Failed to create FluidSynth MIDI input driver");
+#if FLUIDSYNTH_VERSION_MAJOR < 2
+    src->cmd_handler = new_fluid_cmd_handler (src->fluid);
+#else
+    src->cmd_handler = new_fluid_cmd_handler (src->fluid,NULL);
+#endif
+    if (src->cmd_handler) {
+      src->midi = new_fluid_midi_driver (src->settings,
+          fluid_midi_router_handle_midi_event, (void *) (src->midi_router));
+      if (!src->midi)
+        g_warning ("Failed to create FluidSynth MIDI input driver");
+    } else {
+      g_warning ("Failed to create FluidSynth MIDI cmd handler");
+    }
   } else
     g_warning ("Failed to create MIDI input router");
 
@@ -874,7 +920,7 @@ gstbt_fluid_synth_class_init (GstBtFluid
       g_param_spec_enum ("chorus-waveform", "Chorus waveform",
           "Chorus waveform type",
           CHORUS_WAVEFORM_TYPE,
-          FLUID_CHORUS_DEFAULT_TYPE,
+          FLUID_CHORUS_MOD_SINE,
           G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
 
   gst_element_class_set_static_metadata (element_class,
