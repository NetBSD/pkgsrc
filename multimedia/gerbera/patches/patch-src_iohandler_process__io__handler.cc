$NetBSD: patch-src_iohandler_process__io__handler.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/iohandler/process_io_handler.cc.orig	2026-06-25 08:04:59.795206674 +0000
+++ src/iohandler/process_io_handler.cc
@@ -148,7 +148,7 @@ void ProcessIOHandler::open(enum UpnpOpenFileMode mode
 
     if (fd == -1) {
         if (errno == ENXIO) {
-            throw TryAgainException(fmt::format("open failed: {}", std::strerror(errno)));
+            throw TryAgainException(fmt::format("open failed: {}", strerror(errno)));
         }
 
         killAll();
