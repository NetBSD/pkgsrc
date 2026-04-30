$NetBSD: patch-src_multimedia_audio_qaudiosystem__p.h,v 1.1 2026/04/30 06:38:39 adam Exp $

Fix build on NetBSD.

--- src/multimedia/audio/qaudiosystem_p.h.orig	2026-03-27 13:20:17.750424083 +0000
+++ src/multimedia/audio/qaudiosystem_p.h
@@ -229,7 +229,7 @@ inline auto withTemporaryBuffer(size_t bufferSize, Fun
 inline auto withTemporaryBuffer(size_t bufferSize, Functor &&f) noexcept QT_MM_NONBLOCKING
 {
     if (bufferSize <= limit) Q_LIKELY_BRANCH {
-#ifdef alloca
+#if defined(alloca) || defined(__NetBSD__)
         std::byte *stackBuffer = reinterpret_cast<std::byte *>(alloca(bufferSize));
         auto stackBufferSpan = QSpan<std::byte>{
             stackBuffer,
