$NetBSD: patch-kivy_lib_gstplayer___gstplayer.pyx,v 1.1 2023/11/20 06:36:47 wiz Exp $

https://github.com/kivy/kivy/pull/8326/files

--- kivy/lib/gstplayer/_gstplayer.pyx.orig	2023-11-20 06:25:57.768092066 +0000
+++ kivy/lib/gstplayer/_gstplayer.pyx
@@ -225,7 +225,7 @@ cdef class GstPlayer:
         gst_bus_enable_sync_message_emission(self.bus)
         if self.eos_cb or self.message_cb:
             self.hid_message = c_bus_connect_message(
-                    self.bus, _on_gstplayer_message, <void *>self)
+                    self.bus, <buscallback_t>_on_gstplayer_message, <void *>self)
 
         # instantiate the playbin
         self.playbin = gst_element_factory_make('playbin', NULL)
@@ -266,7 +266,7 @@ cdef class GstPlayer:
         # the reference of self in the set_sample_callback() method.
         if self.sample_cb:
             self.hid_sample = c_appsink_set_sample_callback(
-                    self.appsink, _on_appsink_sample, <void *>self)
+                    self.appsink, <appcallback_t>_on_appsink_sample, <void *>self)
 
         # get ready!
         with nogil:
@@ -415,4 +415,4 @@ cdef class GstPlayer:
                     &pending_state, <GstClockTime>GST_SECOND)
             if current_state != GST_STATE_PLAYING:
                 c_appsink_pull_preroll(
-                    self.appsink, _on_appsink_sample, <void *>self)
+                    self.appsink, <appcallback_t>_on_appsink_sample, <void *>self)
