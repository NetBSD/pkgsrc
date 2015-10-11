$NetBSD: patch-src_dominoex_dominoex.cxx,v 1.6 2015/10/11 03:59:56 mef Exp $

(cvs log says)
date: 2015-04-28 08:51:52 +0900;  author: joerg;  state: Exp;  lines: +3 -7;  commitid: 2iTQbBPEdUwBShjy;
Deal with C++11 user defined string literals. Add missing includes.

--- src/dominoex/dominoex.cxx.orig	2015-04-27 23:30:32.000000000 +0000
+++ src/dominoex/dominoex.cxx
@@ -63,7 +63,7 @@ void dominoex::tx_init(SoundBase *sc)
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 
 	videoText();
 }
