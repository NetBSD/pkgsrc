$NetBSD: patch-filter_pdftoopvp_OPVPOutputDev.cxx,v 1.3 2018/05/07 07:59:38 leot Exp $

Fix an invalid conversion error.

--- filter/pdftoopvp/OPVPOutputDev.cxx.orig	2018-02-07 22:08:43.000000000 +0000
+++ filter/pdftoopvp/OPVPOutputDev.cxx
@@ -66,7 +66,7 @@ struct SplashOutFontSubst {
 class SplashOutFontFileID: public SplashFontFileID {
 public:
 
-  SplashOutFontFileID(Ref *rA) { r = *rA; substIdx = -1; }
+  SplashOutFontFileID(const Ref *rA) { r = *rA; substIdx = -1; }
 
   ~SplashOutFontFileID() {}
 
