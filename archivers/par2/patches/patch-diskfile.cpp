$NetBSD: patch-diskfile.cpp,v 1.1 2014/04/25 09:22:13 wiz Exp $

For PATH_MAX.

--- diskfile.cpp.orig	2014-02-27 20:13:23.000000000 +0000
+++ diskfile.cpp
@@ -31,6 +31,7 @@ static char THIS_FILE[]=__FILE__;
 #include <sys/disk.h>
 #define BLKGETSIZE64 DIOCGMEDIASIZE
 #endif
+#include <limits.h>
 
 
 #ifdef WIN32
