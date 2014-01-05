$NetBSD: patch-src_parser_GifParser.cc,v 1.1 2014/01/05 00:29:35 htodd Exp $

--- src/parser/GifParser.cc.orig	2006-11-17 07:24:49.000000000 +0000
+++ src/parser/GifParser.cc
@@ -99,7 +99,7 @@ bool GifParser::parseImage()
 void GifParser::openImage()
 {
   m_nextByteIndex = 0;
-  m_gif = DGifOpen(this, readFromBuffer);
+  m_gif = DGifOpen(this, readFromBuffer, NULL);
   if (!m_gif) {
     throw runtime_error("open gif failed");
   }
