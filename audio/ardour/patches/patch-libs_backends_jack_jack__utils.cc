$NetBSD: patch-libs_backends_jack_jack__utils.cc,v 1.2 2020/03/04 10:56:35 nia Exp $

Realtime JACK currently doesn't work on NetBSD.

This also means it's inadvisable to set the period count.
Let the system worry about latency and don't endure terrible output quality.

Support Sun backend.

https://github.com/Ardour/ardour/pull/468

--- libs/backends/jack/jack_utils.cc.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/backends/jack/jack_utils.cc
@@ -66,6 +66,7 @@ namespace ARDOUR {
 	const char * const coreaudio_driver_name = X_("CoreAudio");
 	const char * const alsa_driver_name = X_("ALSA");
 	const char * const oss_driver_name = X_("OSS");
+	const char * const sun_driver_name = X_("Sun");
 	const char * const freebob_driver_name = X_("FreeBoB");
 	const char * const ffado_driver_name = X_("FFADO");
 	const char * const netjack_driver_name = X_("NetJACK");
@@ -79,6 +80,7 @@ namespace {
 	const char * const coreaudio_driver_command_line_name = X_("coreaudio");
 	const char * const alsa_driver_command_line_name = X_("alsa");
 	const char * const oss_driver_command_line_name = X_("oss");
+	const char * const sun_driver_command_line_name = X_("sun");
 	const char * const freebob_driver_command_line_name = X_("freebob");
 	const char * const ffado_driver_command_line_name = X_("firewire");
 	const char * const netjack_driver_command_line_name = X_("netjack");
@@ -109,6 +111,8 @@ ARDOUR::get_jack_audio_driver_names (vec
 {
 #ifdef PLATFORM_WINDOWS
 	audio_driver_names.push_back (portaudio_driver_name);
+#elif defined(__NetBSD__) || defined(__sun)
+	audio_driver_names.push_back (sun_driver_name);
 #elif __APPLE__
 	audio_driver_names.push_back (coreaudio_driver_name);
 #else
@@ -216,6 +220,9 @@ get_jack_command_line_audio_driver_name 
 	} else if (driver_name == oss_driver_name) {
 		command_line_name = oss_driver_command_line_name;
 		return true;
+	} else if (driver_name == sun_driver_name) {
+		command_line_name = sun_driver_command_line_name;
+		return true;
 	} else if (driver_name == freebob_driver_name) {
 		command_line_name = freebob_driver_command_line_name;
 		return true;
@@ -404,6 +411,12 @@ ARDOUR::get_jack_oss_device_names (devic
 }
 
 void
+ARDOUR::get_jack_sun_device_names (device_map_t& devices)
+{
+	devices.insert (make_pair (default_device_name, default_device_name));
+}
+
+void
 ARDOUR::get_jack_freebob_device_names (device_map_t& devices)
 {
 	devices.insert (make_pair (default_device_name, default_device_name));
@@ -440,6 +453,8 @@ ARDOUR::get_jack_device_names_for_audio_
 		get_jack_alsa_device_names (devices);
 	} else if (driver_name == oss_driver_name) {
 		get_jack_oss_device_names (devices);
+	} else if (driver_name == sun_driver_name) {
+		get_jack_sun_device_names (devices);
 	} else if (driver_name == freebob_driver_name) {
 		get_jack_freebob_device_names (devices);
 	} else if (driver_name == ffado_driver_name) {
@@ -472,7 +487,8 @@ ARDOUR::get_jack_device_names_for_audio_
 bool
 ARDOUR::get_jack_audio_driver_supports_two_devices (const string& driver)
 {
-	return (driver == alsa_driver_name || driver == oss_driver_name);
+	return (driver == alsa_driver_name || driver == oss_driver_name ||
+			driver == sun_driver_name);
 }
 
 bool
@@ -485,8 +501,12 @@ ARDOUR::get_jack_audio_driver_supports_l
 bool
 ARDOUR::get_jack_audio_driver_supports_setting_period_count (const string& driver)
 {
+#ifdef __NetBSD__
+	return false;
+#else
 	return !(driver == dummy_driver_name || driver == coreaudio_driver_name ||
 			driver == portaudio_driver_name);
+#endif
 }
 
 bool
@@ -664,7 +684,11 @@ ARDOUR::JackCommandLineOptions::JackComm
 	, timeout(0)
 	, no_mlock(false)
 	, ports_max(128)
+#ifdef __NetBSD__
+	, realtime(false)
+#else
 	, realtime(true)
+#endif
 	, priority(0)
 	, unlock_gui_libs(false)
 	, verbose(false)
