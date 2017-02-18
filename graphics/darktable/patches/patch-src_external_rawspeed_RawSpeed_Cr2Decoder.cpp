$NetBSD: patch-src_external_rawspeed_RawSpeed_Cr2Decoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/Cr2Decoder.cpp.orig	2017-02-18 19:40:53.670055201 +0000
+++ src/external/rawspeed/RawSpeed/Cr2Decoder.cpp
@@ -280,7 +280,7 @@ void Cr2Decoder::checkSupportInternal(Ca
 
 void Cr2Decoder::decodeMetaDataInternal(CameraMetaData *meta) {
   int iso = 0;
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
   if (data.empty())
