$NetBSD: patch-libs_backends_jack_jack__utils.cc,v 1.3 2021/09/11 16:33:11 nia Exp $

NetBSD needs the -Sr -d sun arguments to jackd.

--- libs/backends/jack/jack_utils.cc.orig	2021-08-13 16:20:07.000000000 +0000
+++ libs/backends/jack/jack_utils.cc
@@ -121,9 +121,10 @@ ARDOUR::get_jack_audio_driver_names (vec
 #ifdef HAVE_ALSA
 	audio_driver_names.push_back (alsa_driver_name);
 #endif
-	audio_driver_names.push_back (oss_driver_name);
-#if defined(__NetBSD__) || defined(__sun)
+#if defined(__NetBSD__)
 	audio_driver_names.push_back (sun_driver_name);
+#else
+	audio_driver_names.push_back (oss_driver_name);
 #endif
 	audio_driver_names.push_back (freebob_driver_name);
 	audio_driver_names.push_back (ffado_driver_name);
@@ -508,7 +509,7 @@ bool
 ARDOUR::get_jack_audio_driver_supports_setting_period_count (const string& driver)
 {
 	return !(driver == dummy_driver_name || driver == coreaudio_driver_name ||
-			driver == portaudio_driver_name);
+			driver == portaudio_driver_name || driver == sun_driver_name);
 }
 
 bool
@@ -689,7 +690,7 @@ ARDOUR::get_jack_command_line_string (Ja
 
 	args.push_back (options.server_path);
 
-#ifdef PLATFORM_WINDOWS
+#if defined(PLATFORM_WINDOWS) || defined(__NetBSD__) || defined(__sun)
 	// must use sync mode on windows
 	args.push_back ("-S");
 #endif
@@ -719,6 +720,7 @@ ARDOUR::get_jack_command_line_string (Ja
 	args.push_back ("-p");
 	args.push_back (to_string(options.ports_max));
 
+#ifndef __NetBSD__
 	if (options.realtime) {
 		args.push_back ("-R");
 		if (options.priority != 0) {
@@ -728,6 +730,9 @@ ARDOUR::get_jack_command_line_string (Ja
 	} else {
 		args.push_back ("-r");
 	}
+#else
+	args.push_back ("-r");
+#endif
 
 	if (options.unlock_gui_libs) {
 		args.push_back ("-u");
