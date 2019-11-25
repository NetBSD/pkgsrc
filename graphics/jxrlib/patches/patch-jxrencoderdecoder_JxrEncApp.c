$NetBSD: patch-jxrencoderdecoder_JxrEncApp.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* Fix warnings, from FreeBSD ports
--- jxrencoderdecoder/JxrEncApp.c.orig	2019-11-16 13:13:44.454384643 +0000
+++ jxrencoderdecoder/JxrEncApp.c
@@ -578,7 +578,7 @@ main(int argc, char* argv[])
 
     //================================
     Call(PKCreateCodecFactory(&pCodecFactory, WMP_SDK_VERSION));
-    Call(pCodecFactory->CreateCodec(&IID_PKImageWmpEncode, &pEncoder));
+    Call(pCodecFactory->CreateCodec(&IID_PKImageWmpEncode, (void**)&pEncoder));
 
     //----------------------------------------------------------------
     Call(PKCreateTestFactory(&pTestFactory, WMP_SDK_VERSION));
