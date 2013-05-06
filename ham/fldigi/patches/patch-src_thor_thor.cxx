$NetBSD: patch-src_thor_thor.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/thor/thor.cxx.orig	2013-05-03 14:19:08.000000000 +0000
+++ src/thor/thor.cxx
@@ -63,7 +63,7 @@ void thor::tx_init(SoundBase *sc)
 	videoText();
 	strSecXmtText = progdefaults.THORsecText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 	cptr = 0;
 }
 
