$NetBSD: patch-src_iohandler_mem__io__handler.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/iohandler/mem_io_handler.cc.orig	2026-06-25 08:09:40.536374639 +0000
+++ src/iohandler/mem_io_handler.cc
@@ -40,14 +40,14 @@ MemIOHandler::MemIOHandler(const void* buffer, int len
     : buffer(new char[length])
     , length(length)
 {
-    std::memcpy(this->buffer, buffer, length);
+    memcpy(this->buffer, buffer, length);
 }
 
 MemIOHandler::MemIOHandler(const std::string& str)
     : buffer(new char[str.length()])
     , length(str.length())
 {
-    std::memcpy(this->buffer, str.c_str(), length);
+    memcpy(this->buffer, str.c_str(), length);
 }
 
 MemIOHandler::~MemIOHandler()
@@ -73,7 +73,7 @@ grb_read_t MemIOHandler::read(std::byte* buf, std::siz
     if (length > static_cast<std::size_t>(rest))
         length = rest;
 
-    std::memcpy(buf, buffer + pos, length);
+    memcpy(buf, buffer + pos, length);
     pos = pos + length;
     ret = length;
 
