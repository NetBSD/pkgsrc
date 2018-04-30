$NetBSD: patch-sdext_source_pdfimport_xpdfwrapper_pdfioutdev__gpl.cxx,v 1.4 2018/04/30 04:46:17 ryoon Exp $

* Fix build with poppler 0.64.0

--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2018-03-29 15:04:09.000000000 +0000
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -446,7 +446,7 @@ int PDFOutDev::parseFont( long long nNew
     FontAttributes aNewFont;
     int nSize = 0;
 
-    GooString* pFamily = gfxFont->getName();
+    GooString* pFamily = const_cast<GooString*>(gfxFont->getName());
     if( pFamily )
     {
         aNewFont.familyName.clear();
@@ -742,7 +742,7 @@ void PDFOutDev::updateFont(GfxState *sta
         FontAttributes aFont;
         int nEmbedSize=0;
 
-        Ref* pID = gfxFont->getID();
+        Ref* pID = const_cast<Ref*>(gfxFont->getID());
         // TODO(Q3): Portability problem
         long long fontID = (long long)pID->gen << 32 | (long long)pID->num;
         std::unordered_map< long long, FontAttributes >::const_iterator it =
@@ -932,7 +932,7 @@ void PDFOutDev::drawChar(GfxState *state
     printf( "\n" );
 }
 
-void PDFOutDev::drawString(GfxState*, GooString* /*s*/)
+void PDFOutDev::drawString(GfxState*, const GooString* /*s*/)
 {
     // TODO(F3): NYI
 }
