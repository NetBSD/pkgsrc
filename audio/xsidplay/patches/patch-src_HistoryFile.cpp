$NetBSD: patch-src_HistoryFile.cpp,v 1.1 2013/04/29 21:14:59 joerg Exp $

--- src/HistoryFile.cpp.orig	2013-04-29 19:14:06.000000000 +0000
+++ src/HistoryFile.cpp
@@ -94,7 +94,7 @@ bool HistoryFile::save(HistoryDialog& di
 #ifdef XSID_HAVE_IOS_BIN
     ofstream toFile(fileName,ios::out|ios::bin|ios::trunc);
 #else
-    ofstream toFile(fileName,ios::out|ios::binary|ios::trunc);
+    ofstream toFile(fileName.ascii(),ios::out|ios::binary|ios::trunc);
 #endif
     if ( !toFile.fail() )
     {
