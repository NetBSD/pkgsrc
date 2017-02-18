$NetBSD: patch-src_external_rawspeed_RawSpeed_Rw2Decoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/Rw2Decoder.cpp.orig	2017-02-18 19:41:04.240843715 +0000
+++ src/external/rawspeed/RawSpeed/Rw2Decoder.cpp
@@ -211,7 +211,7 @@ void Rw2Decoder::checkSupportInternal(Ca
 }
 
 void Rw2Decoder::decodeMetaDataInternal(CameraMetaData *meta) {
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_BLUE, CFA_GREEN, CFA_GREEN2, CFA_RED);
+  mRaw->cfa.setCFA(2, 2, CFA_BLUE, CFA_GREEN, CFA_GREEN2, CFA_RED);
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
   if (data.empty())
