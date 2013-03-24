$NetBSD: patch-APIModules_QTSSReflectorModule_QTSSReflectorModule.cpp,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- APIModules/QTSSReflectorModule/QTSSReflectorModule.cpp.orig	2005-07-31 09:00:31.000000000 +0000
+++ APIModules/QTSSReflectorModule/QTSSReflectorModule.cpp
@@ -1114,7 +1114,7 @@ void DoDescribeAddRequiredSDPLines(QTSS_
             editedSDP->Put("o=broadcast_sdp ");
             char tempBuff[256]= "";               
             tempBuff[255] = 0;
-            qtss_snprintf(tempBuff,sizeof(tempBuff) - 1, "%lu", (UInt32) theSession);
+            qtss_snprintf(tempBuff,sizeof(tempBuff) - 1, "%lu", (UInt32)(uintptr_t) theSession);
             editedSDP->Put(tempBuff);
 
             editedSDP->Put(" ");
