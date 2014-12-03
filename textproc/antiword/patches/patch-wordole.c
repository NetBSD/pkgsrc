$NetBSD: patch-wordole.c,v 1.1.2.2 2014/12/03 08:48:58 tron Exp $

Fix for CVE-2014-8123 from Fabian Keil.

--- wordole.c.orig	2005-08-26 19:49:57.000000000 +0000
+++ wordole.c
@@ -259,6 +259,11 @@ bGetPPS(FILE *pFile,
 		}
 		tNameSize = (size_t)usGetWord(0x40, aucBytes);
 		tNameSize = (tNameSize + 1) / 2;
+		if (tNameSize >= sizeof(atPPSlist[0].szName)) {
+			werr(0, "PPS %d appears to be invalid.", iIndex);
+			atPPSlist = xfree(atPPSlist);
+			return FALSE;
+		}
 		vName2String(atPPSlist[iIndex].szName, aucBytes, tNameSize);
 		atPPSlist[iIndex].ucType = ucGetByte(0x42, aucBytes);
 		if (atPPSlist[iIndex].ucType == 5) {
