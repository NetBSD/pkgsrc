$NetBSD: patch-src_external_rawspeed_RawSpeed_PefDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/PefDecoder.cpp.orig	2017-02-18 19:41:02.200086539 +0000
+++ src/external/rawspeed/RawSpeed/PefDecoder.cpp
@@ -95,7 +95,7 @@ void PefDecoder::checkSupportInternal(Ca
 
 void PefDecoder::decodeMetaDataInternal(CameraMetaData *meta) {
   int iso = 0;
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
   if (data.empty())
