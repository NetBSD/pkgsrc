$NetBSD: patch-src_dominoex_dominoex.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/dominoex/dominoex.cxx.orig	2013-05-03 14:18:53.000000000 +0000
+++ src/dominoex/dominoex.cxx
@@ -64,7 +64,7 @@ void dominoex::tx_init(SoundBase *sc)
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 
 	videoText();
 }
