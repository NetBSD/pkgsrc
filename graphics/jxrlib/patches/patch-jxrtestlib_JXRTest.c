$NetBSD: patch-jxrtestlib_JXRTest.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* fix warnings, from FreeBSD ports
--- jxrtestlib/JXRTest.c.orig	2013-03-19 19:06:18.000000000 +0000
+++ jxrtestlib/JXRTest.c
@@ -198,7 +198,7 @@ ERR PKTestFactory_CreateDecoderFromFile(
     ERR err = WMP_errSuccess;
 
     char *pExt = NULL;
-    PKIID* pIID = NULL;
+    const PKIID* pIID = NULL;
 
     struct WMPStream* pStream = NULL;
     PKImageDecode* pDecoder = NULL;
@@ -214,7 +214,7 @@ ERR PKTestFactory_CreateDecoderFromFile(
     Call(CreateWS_File(&pStream, szFilename, "rb"));
 
     // Create decoder
-    Call(PKTestFactory_CreateCodec(pIID, ppDecoder));
+    Call(PKTestFactory_CreateCodec(pIID,(void**)ppDecoder));
     pDecoder = *ppDecoder;
 
     // attach stream to decoder
@@ -232,7 +232,7 @@ ERR PKCreateTestFactory(PKCodecFactory**
 
     UNREFERENCED_PARAMETER( uVersion );
 
-    Call(PKAlloc(ppCFactory, sizeof(**ppCFactory)));
+    Call(PKAlloc((void**)ppCFactory, sizeof(**ppCFactory)));
     pCFactory = *ppCFactory;
 
     pCFactory->CreateCodec = PKTestFactory_CreateCodec;
@@ -287,7 +287,7 @@ ERR PKTestDecode_Release(
 
     pID->fStreamOwner && pID->pStream->Close(&pID->pStream);
 
-    return PKFree(ppID);
+    return PKFree((void**)ppID);
 }
 
 ERR PKTestDecode_Create(
@@ -296,7 +296,7 @@ ERR PKTestDecode_Create(
     ERR err = WMP_errSuccess;
     PKTestDecode* pID = NULL;
 
-    Call(PKAlloc(ppID, sizeof(**ppID)));
+    Call(PKAlloc((void**)ppID, sizeof(**ppID)));
 
     pID = *ppID;
     pID->Initialize = PKTestDecode_Initialize;
