$NetBSD: patch-src_external_rawspeed_RawSpeed_OrfDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/OrfDecoder.cpp.orig	2017-02-18 19:40:59.878456264 +0000
+++ src/external/rawspeed/RawSpeed/OrfDecoder.cpp
@@ -264,7 +264,7 @@ void OrfDecoder::checkSupportInternal(Ca
 
 void OrfDecoder::decodeMetaDataInternal(CameraMetaData *meta) {
   int iso = 0;
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN, CFA_BLUE);
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
   if (data.empty())
