$NetBSD: patch-src_external_rawspeed_RawSpeed_ArwDecoder.cpp,v 1.1 2017/02/18 23:17:02 joerg Exp $

--- src/external/rawspeed/RawSpeed/ArwDecoder.cpp.orig	2017-02-18 19:40:50.868914278 +0000
+++ src/external/rawspeed/RawSpeed/ArwDecoder.cpp
@@ -257,7 +257,7 @@ void ArwDecoder::decodeMetaDataInternal(
   //Default
   int iso = 0;
 
-  mRaw->cfa.setCFA(iPoint2D(2,2), CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
+  mRaw->cfa.setCFA(2, 2, CFA_RED, CFA_GREEN, CFA_GREEN2, CFA_BLUE);
   vector<TiffIFD*> data = mRootIFD->getIFDsWithTag(MODEL);
 
   if (data.empty())
