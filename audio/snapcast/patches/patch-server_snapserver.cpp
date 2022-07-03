$NetBSD: patch-server_snapserver.cpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Don't hardcode various paths, allow pkgsrc to substitute them.

--- server/snapserver.cpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ server/snapserver.cpp
@@ -58,7 +58,7 @@ int main(int argc, char* argv[])
     {
         ServerSettings settings;
         std::string pcmSource = "pipe:///tmp/snapfifo?name=default";
-        std::string config_file = "/etc/snapserver.conf";
+        std::string config_file = "@PKG_SYSCONFDIR@/snapserver.conf";
 
         OptionParser op("Allowed options");
         auto helpSwitch = op.add<Switch>("h", "help", "Produce help message, use -hh to show options from config file");
@@ -252,7 +252,7 @@ int main(int argc, char* argv[])
                 throw std::invalid_argument("user must not be empty");
 
             if (settings.server.data_dir.empty())
-                settings.server.data_dir = "/var/lib/snapserver";
+                settings.server.data_dir = "@VARBASE@/lib/snapserver";
             Config::instance().init(settings.server.data_dir, settings.server.user, settings.server.group);
 
             daemon = std::make_unique<Daemon>(settings.server.user, settings.server.group, settings.server.pid_file);
