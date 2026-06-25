$NetBSD: patch-src_metadata_metacontent__handler.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/metadata/metacontent_handler.cc.orig	2026-06-25 08:00:09.711859564 +0000
+++ src/metadata/metacontent_handler.cc
@@ -316,7 +316,7 @@ std::unique_ptr<IOHandler> FanArtHandler::serveContent
     struct stat statbuf;
     int ret = stat(path.c_str(), &statbuf);
     if (ret != 0) {
-        log_warning("File does not exist: {} ({})", path.c_str(), std::strerror(errno));
+        log_warning("File does not exist: {} ({})", path.c_str(), strerror(errno));
         return nullptr;
     }
     return std::make_unique<FileIOHandler>(path);
@@ -381,7 +381,7 @@ std::unique_ptr<IOHandler> ContainerArtHandler::serveC
     struct stat statbuf;
     int ret = stat(path.c_str(), &statbuf);
     if (ret != 0) {
-        log_warning("File does not exist: {} ({})", path.c_str(), std::strerror(errno));
+        log_warning("File does not exist: {} ({})", path.c_str(), strerror(errno));
         return nullptr;
     }
     return std::make_unique<FileIOHandler>(path);
@@ -465,7 +465,7 @@ std::unique_ptr<IOHandler> SubtitleHandler::serveConte
     struct stat statbuf;
     int ret = stat(path.c_str(), &statbuf);
     if (ret != 0) {
-        log_warning("File does not exist: {} ({})", path.c_str(), std::strerror(errno));
+        log_warning("File does not exist: {} ({})", path.c_str(), strerror(errno));
         return nullptr;
     }
     return std::make_unique<FileIOHandler>(path);
@@ -556,7 +556,7 @@ std::unique_ptr<IOHandler> ResourceHandler::serveConte
     struct stat statbuf;
     int ret = stat(path.c_str(), &statbuf);
     if (ret != 0) {
-        log_warning("File does not exist: {} ({})", path.string(), std::strerror(errno));
+        log_warning("File does not exist: {} ({})", path.string(), strerror(errno));
         return nullptr;
     }
     return std::make_unique<FileIOHandler>(path);
