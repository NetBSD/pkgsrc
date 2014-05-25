$NetBSD: patch-src_parser_GifParser.cc,v 1.2 2014/05/25 08:04:00 obache Exp $

* giflib>=5 API changes

--- src/parser/GifParser.cc.orig	2006-11-17 07:24:49.000000000 +0000
+++ src/parser/GifParser.cc
@@ -81,7 +81,7 @@ GifParser::GifParser(Message *message,
 GifParser::~GifParser()
 {
   if (m_gif) {
-    DGifCloseFile(m_gif);
+    DGifCloseFile(m_gif, NULL);
   }
 }
 
@@ -99,7 +99,7 @@ bool GifParser::parseImage()
 void GifParser::openImage()
 {
   m_nextByteIndex = 0;
-  m_gif = DGifOpen(this, readFromBuffer);
+  m_gif = DGifOpen(this, readFromBuffer, NULL);
   if (!m_gif) {
     throw runtime_error("open gif failed");
   }
