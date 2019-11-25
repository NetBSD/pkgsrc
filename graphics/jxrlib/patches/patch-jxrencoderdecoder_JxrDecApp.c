$NetBSD: patch-jxrencoderdecoder_JxrDecApp.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* fix warnings, from FreeBSD ports  
--- jxrencoderdecoder/JxrDecApp.c.orig	2019-11-25 19:14:26.881820454 +0000
+++ jxrencoderdecoder/JxrDecApp.c
@@ -423,7 +423,7 @@ ERR WmpDecAppCreateEncoderFromExt(
     Call(GetTestEncodeIID(szExt, &pIID));
 
     // Create encoder
-    Call(PKTestFactory_CreateCodec(pIID, ppIE));
+    Call(PKTestFactory_CreateCodec(pIID, (void**)ppIE));
 
 Cleanup:
     return err;
