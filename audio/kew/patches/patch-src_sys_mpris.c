$NetBSD: patch-src_sys_mpris.c,v 1.1 2026/02/12 12:55:00 ktnb Exp $

Apply USE_DBUS correctly. https://github.com/ravachol/kew/issues/538

--- src/sys/mpris.c.orig	2026-02-12 02:30:02.240433498 +0000
+++ src/sys/mpris.c
@@ -23,7 +23,7 @@
 #include <glib.h>
 #include <math.h>
 
-#ifndef __APPLE__
+#ifdef USE_DBUS
 
 static guint registration_id;
 static guint bus_name_id;
@@ -365,7 +365,7 @@ static void handle_set_position(GDBusConnection *conne
 }
 #endif
 
-#ifndef __APPLE__
+#ifdef USE_DBUS
 static void handle_method_call(GDBusConnection *connection, const gchar *sender,
                                const gchar *object_path,
                                const gchar *interface_name,
@@ -413,7 +413,7 @@ static void handle_method_call(GDBusConnection *connec
 }
 #endif
 
-#ifndef __APPLE__
+#ifdef USE_DBUS
 static void on_bus_name_acquired(GDBusConnection *connection, const gchar *name,
                                  gpointer user_data)
 {
@@ -808,7 +808,7 @@ static gboolean get_can_control(GDBusConnection *conne
 }
 #endif
 
-#ifndef __APPLE__
+#ifdef USE_DBUS
 static GVariant *get_property_callback(GDBusConnection *connection,
                                        const gchar *sender,
                                        const gchar *object_path,
@@ -950,7 +950,7 @@ set_property_callback(GDBusConnection *connection, con
 }
 #endif
 
-#ifndef __APPLE__
+#ifdef USE_DBUS
 // MPRIS MediaPlayer2 interface vtable
 static const GDBusInterfaceVTable media_player_interface_vtable = {
     .method_call = handle_method_call, // We're using individual method handlers
@@ -971,7 +971,7 @@ void emit_playback_stopped_mpris()
 
 void emit_playback_stopped_mpris()
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         if (get_gd_bus_connection()) {
                 g_dbus_connection_call(
                     get_gd_bus_connection(), NULL, "/org/mpris/MediaPlayer2",
@@ -987,7 +987,7 @@ void cleanup_mpris(void)
 
 void cleanup_mpris(void)
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         if (registration_id > 0) {
                 g_dbus_connection_unregister_object(get_gd_bus_connection(),
                                                     registration_id);
@@ -1019,7 +1019,7 @@ void init_mpris(void)
 
 void init_mpris(void)
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         AppState *state = get_app_state();
 
         if (get_g_main_context() == NULL) {
@@ -1080,7 +1080,7 @@ void emit_start_playing_mpris()
 
 void emit_start_playing_mpris()
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         GVariant *parameters = g_variant_new("(s)", "Playing");
         g_dbus_connection_emit_signal(
             get_gd_bus_connection(), NULL, "/org/mpris/MediaPlayer2",
@@ -1106,14 +1106,14 @@ gchar *sanitize_title(const gchar *title)
         return sanitized_dup;
 }
 
-#ifndef __APPLE__
+#ifdef USE_DBUS
 static guint64 last_emit_time = 0;
 #endif
 
 void emit_properties_changed(GDBusConnection *connection,
                              const gchar *property_name, GVariant *new_value)
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         GVariantBuilder changed_properties_builder;
 
         if (connection == NULL || property_name == NULL || new_value == NULL)
@@ -1151,7 +1151,7 @@ void emit_volume_changed(void)
 
 void emit_volume_changed(void)
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         gdouble newVolume = (gdouble)get_current_volume() / 100;
 
         if (newVolume > 1.0)
@@ -1165,7 +1165,7 @@ void emit_shuffle_changed(void)
 
 void emit_shuffle_changed(void)
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         gboolean shuffle_enabled = is_shuffle_enabled();
 
         // Emit the PropertiesChanged signal for the volume property
@@ -1178,7 +1178,7 @@ void emit_metadata_changed(const gchar *title, const g
                            const gchar *album, const gchar *cover_art_path,
                            const gchar *track_id, Node *current_song, gint64 length)
 {
-#ifndef __APPLE__
+#ifdef USE_DBUS
         guint64 current_time = g_get_monotonic_time();
         if (current_time - last_emit_time < 500000) // 0.5 seconds
         {
