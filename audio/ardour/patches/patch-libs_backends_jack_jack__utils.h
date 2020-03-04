$NetBSD: patch-libs_backends_jack_jack__utils.h,v 1.2 2020/03/04 10:56:35 nia Exp $

Support Sun backend.

https://github.com/Ardour/ardour/pull/468

--- libs/backends/jack/jack_utils.h.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/backends/jack/jack_utils.h
@@ -30,6 +30,7 @@ namespace ARDOUR {
 	extern const char * const coreaudio_driver_name;
 	extern const char * const alsa_driver_name;
 	extern const char * const oss_driver_name;
+	extern const char * const sun_driver_name;
 	extern const char * const freebob_driver_name;
 	extern const char * const ffado_driver_name;
 	extern const char * const netjack_driver_name;
@@ -110,6 +111,7 @@ namespace ARDOUR {
 	void get_jack_portaudio_device_names (device_map_t& devices);
 	void get_jack_coreaudio_device_names (device_map_t& devices);
 	void get_jack_oss_device_names (device_map_t& devices);
+	void get_jack_sun_device_names (device_map_t& devices);
 	void get_jack_freebob_device_names (device_map_t& devices);
 	void get_jack_ffado_device_names (device_map_t& devices);
 	void get_jack_netjack_device_names (device_map_t& devices);
