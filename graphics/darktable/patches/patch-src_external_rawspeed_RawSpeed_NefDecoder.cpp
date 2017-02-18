$NetBSD: patch-src_external_rawspeed_RawSpeed_NefDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/NefDecoder.cpp.orig	2017-02-18 19:40:57.837514025 +0000
+++ src/external/rawspeed/RawSpeed/NefDecoder.cpp
@@ -411,7 +411,7 @@ string NefDecoder::getExtendedMode(strin
 
 void NefDecoder::decodeMetaDataInternal(CameraMetaData *meta) {
   int iso = 0;
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
 
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
