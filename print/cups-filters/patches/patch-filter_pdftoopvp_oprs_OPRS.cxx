$NetBSD: patch-filter_pdftoopvp_oprs_OPRS.cxx,v 1.1 2015/07/15 12:49:37 wiz Exp $

pdftoopvp: Adaptations to API changes on Poppler 0.34.0.
http://bzr.linuxfoundation.org/loggerhead/openprinting/cups-filters/revision/7371

--- filter/pdftoopvp/oprs/OPRS.cxx.orig	2015-06-26 15:45:26.000000000 +0000
+++ filter/pdftoopvp/oprs/OPRS.cxx
@@ -240,8 +240,10 @@ SplashError OPRS::drawImage(SplashImageS
     if (rasterMode) {
 #if POPPLER_VERSION_MAJOR <= 0 && (POPPLER_VERSION_MINOR <= 20 || (POPPLER_VERSION_MINOR == 21 && POPPLER_VERSION_MICRO <= 2))
 	return splash->drawImage(src,srcData,srcMode,srcAlpha,w,h,mat);
-#else
+#elif POPPLER_VERSION_MAJOR <= 0 && POPPLER_VERSION_MINOR <= 33
 	return splash->drawImage(src,srcData,srcMode,srcAlpha,w,h,mat,gFalse);
+#else
+	return splash->drawImage(src,0,srcData,srcMode,srcAlpha,w,h,mat,gFalse);
 #endif
     } else {
 	return opvpSplash->drawImage(src,srcData,srcMode,srcAlpha,w,h,mat);
