$NetBSD: patch-sdext_source_pdfimport_xpdfwrapper_pdfioutdev__gpl.hxx,v 1.1 2018/04/30 04:46:17 ryoon Exp $

* Fix build with poppler 0.64.0

--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2018-03-29 15:04:09.000000000 +0000
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx
@@ -223,7 +223,7 @@ namespace pdfi
                               double dx, double dy,
                               double originX, double originY,
                               CharCode code, int nBytes, Unicode *u, int uLen) override;
-        virtual void drawString(GfxState *state, GooString *s) override;
+        virtual void drawString(GfxState *state, const GooString *s) override;
         virtual void endTextObject(GfxState *state) override;
 
         //----- image drawing
