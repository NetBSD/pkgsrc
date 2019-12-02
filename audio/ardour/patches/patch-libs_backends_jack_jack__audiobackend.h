$NetBSD: patch-libs_backends_jack_jack__audiobackend.h,v 1.1 2019/12/02 13:34:33 nia Exp $

Allow specifying a default sampling rate.

--- libs/backends/jack/jack_audiobackend.h.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/backends/jack/jack_audiobackend.h
@@ -54,6 +54,8 @@ class JACKAudioBackend : public AudioBac
     std::vector<std::string> enumerate_drivers () const;
     int set_driver (const std::string&);
 
+    float default_sample_rate () const;
+
     std::vector<DeviceStatus> enumerate_devices () const;
 
     std::vector<float> available_sample_rates (const std::string& device) const;
