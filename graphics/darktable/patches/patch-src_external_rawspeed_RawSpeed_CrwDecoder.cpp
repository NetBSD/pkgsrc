$NetBSD: patch-src_external_rawspeed_RawSpeed_CrwDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/CrwDecoder.cpp.orig	2017-02-18 19:40:55.750611715 +0000
+++ src/external/rawspeed/RawSpeed/CrwDecoder.cpp
@@ -105,7 +105,7 @@ static float canonEv(const long in) {
 
 void CrwDecoder::decodeMetaDataInternal(CameraMetaData *meta) {
   int iso = 0;
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
   vector<CiffIFD*> data = mRootIFD->getIFDsWithTag(CIFF_MAKEMODEL);
   if (data.empty())
     ThrowRDE("CRW Support check: Model name not found");
