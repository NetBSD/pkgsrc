$NetBSD: patch-filter_pdftoopvp_OPVPOutputDev.cxx,v 1.1 2015/07/15 12:49:37 wiz Exp $

pdftoopvp: Adaptations to API changes on Poppler 0.34.0.
http://bzr.linuxfoundation.org/loggerhead/openprinting/cups-filters/revision/7371

--- filter/pdftoopvp/OPVPOutputDev.cxx.orig	2015-06-26 15:45:26.000000000 +0000
+++ filter/pdftoopvp/OPVPOutputDev.cxx
@@ -1811,10 +1811,14 @@ void OPVPOutputDev::drawSoftMaskedImage(
 #if POPPLER_VERSION_MAJOR <= 0 && (POPPLER_VERSION_MINOR <= 20 || (POPPLER_VERSION_MINOR == 21 && POPPLER_VERSION_MICRO <= 2))
   maskSplash->drawImage(&imageSrc, &imgMaskData,
 			splashModeMono8, gFalse, maskWidth, maskHeight, mat);
-#else
+#elif POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR <= 33
   maskSplash->drawImage(&imageSrc, &imgMaskData,
 			splashModeMono8, gFalse, maskWidth, maskHeight,
                         mat,gFalse);
+#else
+  maskSplash->drawImage(&imageSrc, 0, &imgMaskData,
+                          splashModeMono8, gFalse, maskWidth, maskHeight,
+			                          mat,gFalse);
 #endif
   delete imgMaskData.imgStr;
   maskStr->close();
