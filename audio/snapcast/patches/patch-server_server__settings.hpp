$NetBSD: patch-server_server__settings.hpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Don't hardcode various paths, allow pkgsrc to substitute them.

--- server/server_settings.hpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ server/server_settings.hpp
@@ -30,7 +30,7 @@ struct ServerSettings
     struct Server
     {
         int threads{-1};
-        std::string pid_file{"/var/run/snapserver/pid"};
+        std::string pid_file{"@VARBASE@/run/snapserver/pid"};
         std::string user{"snapserver"};
         std::string group{""};
         std::string data_dir{""};
