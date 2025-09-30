$NetBSD: patch-client_snapclient.cpp,v 1.2 2025/09/30 06:49:37 adam Exp $

Add Sun Audio support for NetBSD.

--- client/snapclient.cpp.orig	2025-09-23 19:02:05.000000000 +0000
+++ client/snapclient.cpp
@@ -28,6 +28,9 @@
 #ifdef HAS_PULSE
 #include "player/pulse_player.hpp"
 #endif
+#ifdef HAS_SUN
+#include "player/sun_player.hpp"
+#endif
 #ifdef HAS_WASAPI
 #include "player/wasapi_player.hpp"
 #endif
@@ -73,7 +76,7 @@ namespace
 PcmDevice getPcmDevice(const std::string& player, const std::string& parameter, const std::string& soundcard)
 {
     LOG(DEBUG, LOG_TAG) << "Trying to get PCM device for player: " << player << ", parameter: " << ", card: " << soundcard << "\n";
-#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_PIPEWIRE)
+#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_PIPEWIRE) || defined(HAS_SUN)
     vector<PcmDevice> pcm_devices;
 #if defined(HAS_ALSA)
     if (player == player::ALSA)
@@ -186,7 +189,7 @@ int main(int argc, char** argv)
             op.add<Implicit<std::filesystem::path>>("", "server-cert", "Verify server with CA certificate (PEM format)", "default certificates");
 
 // PCM device specific
-#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_PIPEWIRE)
+#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_PIPEWIRE) || defined(HAS_SUN)
         auto listSwitch = op.add<Switch>("l", "list", "List PCM devices");
         op.add<Value<string>>("s", "soundcard", "Index or name of the PCM device", pcm_device, &pcm_device);
 #endif
@@ -258,7 +261,7 @@ int main(int argc, char** argv)
 
         settings.player.player_name = utils::string::split_left(settings.player.player_name, ':', settings.player.parameter);
 
-#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_PIPEWIRE)
+#if defined(HAS_ALSA) || defined(HAS_PULSE) || defined(HAS_WASAPI) || defined(HAS_PIPEWIRE) || defined(HAS_SUN)
         if (listSwitch->is_set())
         {
             try
@@ -272,6 +275,10 @@ int main(int argc, char** argv)
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
