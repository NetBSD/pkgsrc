$NetBSD: patch-src_ConfigFileOld.cpp,v 1.1 2013/04/29 21:14:58 joerg Exp $

--- src/ConfigFileOld.cpp.orig	2013-04-29 19:09:27.000000000 +0000
+++ src/ConfigFileOld.cpp
@@ -339,7 +339,7 @@ bool ConfigFileOld::save()
 #ifdef XSID_HAVE_IOS_BIN
     ofstream toFile(fileName,ios::out|ios::bin|ios::trunc);
 #else
-    ofstream toFile(fileName,ios::out|ios::binary|ios::trunc);
+    ofstream toFile(fileName.ascii(),ios::out|ios::binary|ios::trunc);
 #endif
     if ( !toFile.fail() )
     {
