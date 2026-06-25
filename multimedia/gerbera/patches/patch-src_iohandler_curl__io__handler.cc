$NetBSD: patch-src_iohandler_curl__io__handler.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/iohandler/curl_io_handler.cc.orig	2026-06-25 08:06:49.062007872 +0000
+++ src/iohandler/curl_io_handler.cc
@@ -237,9 +237,9 @@ std::size_t CurlIOHandler::curlCallback(void* ptr, std
 
     lock.unlock();
 
-    std::memcpy(ego->buffer + bLocal, ptr, write1);
+    memcpy(ego->buffer + bLocal, ptr, write1);
     if (write2)
-        std::memcpy(ego->buffer, static_cast<char*>(ptr) + maxWrite, write2);
+        memcpy(ego->buffer, static_cast<char*>(ptr) + maxWrite, write2);
 
     lock.lock();
 
