$NetBSD: patch-sdext_source_pdfimport_xpdfwrapper_pdfioutdev__gpl.cxx,v 1.6 2018/12/04 12:56:49 ryoon Exp $

--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2018-10-29 19:55:29.000000000 +0000
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -514,7 +514,7 @@ void PDFOutDev::printPath( GfxPath* pPat
 PDFOutDev::PDFOutDev( PDFDoc* pDoc ) :
     m_pDoc( pDoc ),
     m_aFontMap(),
-    m_pUtf8Map( new UnicodeMap("UTF-8", gTrue, &mapUTF8) ),
+    m_pUtf8Map( new UnicodeMap("UTF-8", true, &mapUTF8) ),
     m_bSkipImages(false)
 {
 }
@@ -578,7 +578,7 @@ void PDFOutDev::restoreState(GfxState*)
     printf( "restoreState\n" );
 }
 
-void PDFOutDev::setDefaultCTM(double *pMat)
+void PDFOutDev::setDefaultCTM(const double *pMat)
 {
     assert(pMat);
 
@@ -939,11 +939,11 @@ void PDFOutDev::endTextObject(GfxState*)
 }
 
 void PDFOutDev::drawImageMask(GfxState* pState, Object*, Stream* str,
-                              int width, int height, GBool invert,
+                              int width, int height, bool invert,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                              GBool /*interpolate*/,
+                              bool /*interpolate*/,
 #endif
-                              GBool /*inlineImg*/ )
+                              bool /*inlineImg*/ )
 {
     if (m_bSkipImages)
         return;
@@ -972,9 +972,9 @@ void PDFOutDev::drawImageMask(GfxState* 
 void PDFOutDev::drawImage(GfxState*, Object*, Stream* str,
                           int width, int height, GfxImageColorMap* colorMap,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                          GBool /*interpolate*/,
+                          bool /*interpolate*/,
 #endif
-                          int* maskColors, GBool /*inlineImg*/ )
+                          int* maskColors, bool /*inlineImg*/ )
 {
     if (m_bSkipImages)
         return;
@@ -1023,13 +1023,13 @@ void PDFOutDev::drawMaskedImage(GfxState
                                 int width, int height,
                                 GfxImageColorMap* colorMap,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                GBool /*interpolate*/,
+                                bool /*interpolate*/,
 #endif
                                 Stream* maskStr,
                                 int maskWidth, int maskHeight,
-                                GBool maskInvert
+                                bool maskInvert
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                , GBool /*maskInterpolate*/
+                                , bool /*maskInterpolate*/
 #endif
                                )
 {
@@ -1045,13 +1045,13 @@ void PDFOutDev::drawSoftMaskedImage(GfxS
                                     int width, int height,
                                     GfxImageColorMap* colorMap,
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                    GBool /*interpolate*/,
+                                    bool /*interpolate*/,
 #endif
                                     Stream* maskStr,
                                     int maskWidth, int maskHeight,
                                     GfxImageColorMap* maskColorMap
 #if POPPLER_CHECK_VERSION(0, 12, 0)
-                                    , GBool /*maskInterpolate*/
+                                    , bool /*maskInterpolate*/
 #endif
                                    )
 {
