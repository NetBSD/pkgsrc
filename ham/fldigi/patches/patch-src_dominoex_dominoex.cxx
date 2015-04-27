$NetBSD: patch-src_dominoex_dominoex.cxx,v 1.5 2015/04/27 23:51:52 joerg Exp $

--- src/dominoex/dominoex.cxx.orig	2015-04-27 23:30:32.000000000 +0000
+++ src/dominoex/dominoex.cxx
@@ -63,7 +63,7 @@ void dominoex::tx_init(SoundBase *sc)
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 
 	videoText();
 }
