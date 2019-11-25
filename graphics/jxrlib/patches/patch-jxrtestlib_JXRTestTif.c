$NetBSD: patch-jxrtestlib_JXRTestTif.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* Fix warnings, from FreeBSD ports
--- jxrtestlib/JXRTestTif.c.orig	2013-03-19 19:17:12.000000000 +0000
+++ jxrtestlib/JXRTestTif.c
@@ -909,8 +909,8 @@ ERR PKImageDecode_Release_TIF(PKTestDeco
 
     PKTestDecode *pID = *ppID;
 
-    Call(WMPFree(&pID->EXT.TIF.uStripOffsets));
-    Call(WMPFree(&pID->EXT.TIF.uStripByteCounts));
+    Call(WMPFree((void**)&pID->EXT.TIF.uStripOffsets));
+    Call(WMPFree((void**)&pID->EXT.TIF.uStripByteCounts));
 
     Call(PKTestDecode_Release(ppID));
 
