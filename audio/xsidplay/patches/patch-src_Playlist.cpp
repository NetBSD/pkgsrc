$NetBSD: patch-src_Playlist.cpp,v 1.1 2013/04/29 21:14:59 joerg Exp $

--- src/Playlist.cpp.orig	2013-04-29 19:14:27.000000000 +0000
+++ src/Playlist.cpp
@@ -373,7 +373,7 @@ bool Playlist::save()
 #ifdef XSID_HAVE_IOS_BIN
     ofstream toFile(fileName,ios::out|ios::bin|ios::trunc);
 #else
-    ofstream toFile(fileName,ios::out|ios::binary|ios::trunc);
+    ofstream toFile(fileName.ascii(),ios::out|ios::binary|ios::trunc);
 #endif
     if ( !toFile.fail() )
     {
