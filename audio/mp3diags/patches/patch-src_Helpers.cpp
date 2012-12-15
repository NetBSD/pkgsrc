$NetBSD: patch-src_Helpers.cpp,v 1.2 2012/12/15 11:10:38 marino Exp $

--- src/Helpers.cpp.orig	2011-09-10 17:51:46.000000000 +0000
+++ src/Helpers.cpp
@@ -20,6 +20,7 @@
  ***************************************************************************/
 
 
+#include  <unistd.h>
 #include  <iostream>
 #include  "fstream_unicode.h"
 #include  <sstream>
@@ -914,7 +915,7 @@ QString getSystemInfo() //ttt2 perhaps s
     filters << "*-release" << "*_version";
     dir.setNameFilters(filters);
     QStringList lFiles (dir.entryList(QDir::Files));
-    utsname utsInfo;
+    struct utsname utsInfo;
     uname(&utsInfo);
     s += utsInfo.sysname; s += " ";
     s += utsInfo.release; s += " ";
