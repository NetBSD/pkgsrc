$NetBSD: patch-faxd_tif__fax3.h,v 1.1 2023/01/05 14:30:13 wiz Exp $

Copy internal code from tiff 4.4 that was removed in 4.5.

--- faxd/tif_fax3.h.orig	2018-09-18 18:51:17.000000000 +0000
+++ faxd/tif_fax3.h
@@ -57,13 +57,7 @@ typedef	void (*TIFFFaxFillFunc)(unsigned
 /*
  * The default run filler; made external for other decoders.
  */
-#if defined(__cplusplus)
-extern "C" {
-#endif
-extern	void _TIFFFax3fillruns(unsigned char*, tiff_runlen_t*, tiff_runlen_t*, tiff_runlen_t);
-#if defined(__cplusplus)
-}
-#endif
+void shopliftedfrom_TIFFFax3fillruns(unsigned char*, tiff_runlen_t*, tiff_runlen_t*, tiff_runlen_t);
 
 
 /* finite state machine codes */
