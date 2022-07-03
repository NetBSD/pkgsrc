$NetBSD: patch-client_snapclient.cpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Add Sun Audio support for NetBSD.

--- client/snapclient.cpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ client/snapclient.cpp
@@ -32,6 +32,9 @@
 #ifdef HAS_PULSE
 #include "player/pulse_player.hpp"
 #endif
+#ifdef HAS_SUN
+#include "player/sun_player.hpp"
+#endif
 #ifdef HAS_WASAPI
 #include "player/wasapi_player.hpp"
 #endif
@@ -62,8 +65,12 @@ PcmDevice getPcmDevice(const std::string
 {
     LOG(DEBUG, LOG_TAG) << "Trying to get PCM device for player: " << player << ", parameter: "
                         << ", card: " << soundcard << "\n";
-#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI)
+#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_SUN)
     vector<PcmDevice> pcm_devices;
+#if defined(HAS_SUN)
+    if (player == player::SUN)
+        pcm_devices = SunPlayer::pcm_list();
+#endif
 #if defined(HAS_ALSA)
     if (player == player::ALSA)
         pcm_devices = AlsaPlayer::pcm_list();
@@ -142,7 +149,7 @@ int main(int argc, char** argv)
         op.add<Value<string>>("", "hostID", "unique host id, default is MAC address", "", &settings.host_id);
 
 // PCM device specific
-#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI)
+#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_SUN)
         auto listSwitch = op.add<Switch>("l", "list", "list PCM devices");
         /*auto soundcardValue =*/op.add<Value<string>>("s", "soundcard", "index or name of the pcm device", pcm_device, &pcm_device);
 #endif
@@ -210,7 +217,7 @@ int main(int argc, char** argv)
 
         settings.player.player_name = utils::string::split_left(settings.player.player_name, ':', settings.player.parameter);
 
-#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI)
+#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_SUN)
         if (listSwitch->is_set())
         {
             try
@@ -224,6 +231,10 @@ int main(int argc, char** argv)
                 if (settings.player.player_name == player::PULSE)
                     pcm_devices = PulsePlayer::pcm_list(settings.player.parameter);
 #endif
+#if defined(HAS_SUN)
+                if (settings.player.player_name == player::SUN)
+                    pcm_devices = SunPlayer::pcm_list();
+#endif
 #if defined(HAS_WASAPI)
                 if (settings.player.player_name == player::WASAPI)
                     pcm_devices = WASAPIPlayer::pcm_list();
