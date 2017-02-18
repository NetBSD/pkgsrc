$NetBSD: patch-src_external_rawspeed_RawSpeed_ThreefrDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/ThreefrDecoder.cpp.orig	2017-02-18 19:41:06.261836198 +0000
+++ src/external/rawspeed/RawSpeed/ThreefrDecoder.cpp
@@ -77,7 +77,7 @@ void ThreefrDecoder::checkSupportInterna
 }
 
 void ThreefrDecoder::decodeMetaDataInternal(CameraMetaData *meta) {
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN, CFA_BLUE);
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
   if (data.empty())
