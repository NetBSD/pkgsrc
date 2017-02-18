$NetBSD: patch-src_external_rawspeed_RawSpeed_AriDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/AriDecoder.cpp.orig	2017-02-18 19:40:48.711688335 +0000
+++ src/external/rawspeed/RawSpeed/AriDecoder.cpp
@@ -104,7 +104,7 @@ void AriDecoder::checkSupportInternal(Ca
 }
 
 void AriDecoder::decodeMetaDataInternal(CameraMetaData *meta) {
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_GREEN, CFA_RED, CFA_BLUE, CFA_GREEN2);
+  mRaw->cfa.setCFA(2, 2, CFA_GREEN, CFA_RED, CFA_BLUE, CFA_GREEN2);
   mRaw->metadata.wbCoeffs[0] = mWB[0];
   mRaw->metadata.wbCoeffs[1] = mWB[1];
   mRaw->metadata.wbCoeffs[2] = mWB[2];
