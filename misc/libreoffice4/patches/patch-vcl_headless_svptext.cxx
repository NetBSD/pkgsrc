$NetBSD: patch-vcl_headless_svptext.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- vcl/headless/svptext.cxx.orig	2014-01-18 00:29:16.000000000 +0000
+++ vcl/headless/svptext.cxx
@@ -172,7 +172,7 @@ void SvpGlyphPeer::RemovingFont( ServerF
 
 void SvpGlyphPeer::RemovingGlyph( ServerFont&, GlyphData& rGlyphData, int /*nGlyphIndex*/ )
 {
-    if( rGlyphData.ExtDataRef().mpData != Format::NONE )
+    if( rGlyphData.ExtDataRef().mpData != NULL )
     {
         // release the glyph related resources
         DBG_ASSERT( (rGlyphData.ExtDataRef().meInfo <= Format::MAX), "SVP::RG() invalid alpha format" );
