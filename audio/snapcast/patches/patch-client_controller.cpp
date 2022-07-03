$NetBSD: patch-client_controller.cpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Add Sun Audio support for NetBSD.

--- client/controller.cpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ client/controller.cpp
@@ -38,6 +38,9 @@
 #ifdef HAS_PULSE
 #include "player/pulse_player.hpp"
 #endif
+#ifdef HAS_SUN
+#include "player/sun_player.hpp"
+#endif
 #ifdef HAS_OPENSL
 #include "player/opensl_player.hpp"
 #endif
@@ -92,6 +95,9 @@ std::unique_ptr<Player> Controller::crea
 std::vector<std::string> Controller::getSupportedPlayerNames()
 {
     std::vector<std::string> result;
+#ifdef HAS_SUN
+    result.emplace_back(player::SUN);
+#endif
 #ifdef HAS_ALSA
     result.emplace_back(player::ALSA);
 #endif
@@ -188,6 +194,10 @@ void Controller::getNextMessage()
             stream_ = make_shared<Stream>(sampleFormat_, settings_.player.sample_format);
             stream_->setBufferLen(std::max(0, serverSettings_->getBufferMs() - serverSettings_->getLatency() - settings_.player.latency));
 
+#ifdef HAS_SUN
+            if (!player_)
+                player_ = createPlayer<SunPlayer>(settings_.player, player::SUN);
+#endif
 #ifdef HAS_ALSA
             if (!player_)
                 player_ = createPlayer<AlsaPlayer>(settings_.player, player::ALSA);
