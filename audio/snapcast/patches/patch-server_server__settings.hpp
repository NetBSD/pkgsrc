$NetBSD: patch-server_server__settings.hpp,v 1.2 2025/09/30 06:49:37 adam Exp $

Don't hardcode various paths, allow pkgsrc to substitute them.

--- server/server_settings.hpp.orig	2025-09-29 07:26:16.191558938 +0000
+++ server/server_settings.hpp
@@ -40,7 +40,7 @@ struct ServerSettings
         /// Number of worker threads
         int threads{-1};
         /// PID file, if running as daemon
-        std::string pid_file{"/var/run/snapserver/pid"};
+        std::string pid_file{"@VARBASE@/run/snapserver/pid"};
         /// User when running as deaemon
         std::string user{"snapserver"};
         /// Group when running as deaemon
@@ -213,9 +213,9 @@ struct ServerSettings
     struct Stream
     {
         /// Directory for stream plugins
-        std::filesystem::path plugin_dir{"/usr/share/snapserver/plug-ins"};
+        std::filesystem::path plugin_dir{"@PREFIX@/share/snapserver/plug-ins"};
         /// Directory for executable process stream sources
-        std::filesystem::path sandbox_dir{"/usr/share/snapserver/sandbox"};
+        std::filesystem::path sandbox_dir{"@PREFIX@/share/snapserver/sandbox"};
         /// Stream sources
         std::vector<std::string> sources;
         /// Default codec
