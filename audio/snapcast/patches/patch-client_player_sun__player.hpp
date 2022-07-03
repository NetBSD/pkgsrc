$NetBSD: patch-client_player_sun__player.hpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Add Sun Audio support for NetBSD.

--- client/player/sun_player.hpp.orig	2022-07-03 13:22:32.864495808 +0000
+++ client/player/sun_player.hpp
@@ -0,0 +1,67 @@
+/***
+    This file is part of snapcast
+    Copyright (C) 2014-2020  Johannes Pohl
+
+    This program is free software: you can redistribute it and/or modify
+    it under the terms of the GNU General Public License as published by
+    the Free Software Foundation, either version 3 of the License, or
+    (at your option) any later version.
+
+    This program is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+    GNU General Public License for more details.
+
+    You should have received a copy of the GNU General Public License
+    along with this program.  If not, see <http://www.gnu.org/licenses/>.
+***/
+
+#ifndef SUN_PLAYER_HPP
+#define SUN_PLAYER_HPP
+
+#include "player.hpp"
+
+#include <chrono>
+#include <optional>
+
+
+namespace player
+{
+
+static constexpr auto SUN = "sun";
+
+/// Audio Player
+/**
+ * Audio player implementation using Sun/NetBSD audio
+ */
+class SunPlayer : public Player
+{
+public:
+    SunPlayer(boost::asio::io_context& io_context, const ClientSettings::Player& settings, std::shared_ptr<Stream> stream);
+    ~SunPlayer() override;
+
+    void start() override;
+    void stop() override;
+
+    /// List the system's audio output devices
+    static std::vector<PcmDevice> pcm_list();
+
+protected:
+    void worker() override;
+    bool needsThread() const override;
+
+private:
+    /// initialize audio device
+    void initSun();
+    /// close audio device
+    void uninitSun();
+
+    int handle_;
+
+    std::recursive_mutex mutex_;
+    std::vector<char> buffer_;
+};
+
+} // namespace player
+
+#endif
