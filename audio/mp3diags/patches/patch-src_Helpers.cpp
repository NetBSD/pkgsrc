$NetBSD: patch-src_Helpers.cpp,v 1.1 2012/01/11 19:25:08 hans Exp $

--- src/Helpers.cpp.orig	2011-09-10 19:51:46.000000000 +0200
+++ src/Helpers.cpp	2012-01-02 11:31:20.777472032 +0100
@@ -914,7 +914,7 @@ QString getSystemInfo() //ttt2 perhaps s
     filters << "*-release" << "*_version";
     dir.setNameFilters(filters);
     QStringList lFiles (dir.entryList(QDir::Files));
-    utsname utsInfo;
+    struct utsname utsInfo;
     uname(&utsInfo);
     s += utsInfo.sysname; s += " ";
     s += utsInfo.release; s += " ";
