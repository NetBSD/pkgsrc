$NetBSD: patch-libs_backends_jack_jack__audiobackend.cc,v 1.1 2019/12/02 13:34:33 nia Exp $

Default to 48000 since it seems to avoid some problems with the 44100
fallback....

Realtime JACK currently doesn't work on NetBSD.

--- libs/backends/jack/jack_audiobackend.cc.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/backends/jack/jack_audiobackend.cc
@@ -118,6 +118,12 @@ JACKAudioBackend::set_driver (const std:
 	return 0;
 }
 
+float
+JACKAudioBackend::default_sample_rate () const
+{
+	return 48000.0;
+}
+
 vector<AudioBackend::DeviceStatus>
 JACKAudioBackend::enumerate_devices () const
 {
@@ -504,7 +510,11 @@ JACKAudioBackend::setup_jack_startup_com
 	if (_target_sample_format == FormatInt16) {
 		options.force16_bit = _target_sample_format;
 	}
+#ifdef __NetBSD__
+	options.realtime = false;
+#else
 	options.realtime = true;
+#endif
 	options.ports_max = 2048;
 
 	ARDOUR::set_midi_option (options, _target_midi_option);
