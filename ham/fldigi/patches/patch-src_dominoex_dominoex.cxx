$NetBSD: patch-src_dominoex_dominoex.cxx,v 1.2 2013/09/13 06:35:55 mef Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/dominoex/dominoex.cxx.orig	2013-05-03 14:18:53.000000000 +0000
+++ src/dominoex/dominoex.cxx
@@ -64,7 +64,7 @@ void dominoex::tx_init(SoundBase *sc)
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 
 	videoText();
 }
