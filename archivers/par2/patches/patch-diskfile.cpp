$NetBSD: patch-diskfile.cpp,v 1.2 2014/04/25 09:24:22 wiz Exp $

For PATH_MAX.
https://github.com/BlackIkeEagle/par2cmdline/issues/28

--- diskfile.cpp.orig	2014-02-27 20:13:23.000000000 +0000
+++ diskfile.cpp
@@ -31,6 +31,7 @@ static char THIS_FILE[]=__FILE__;
 #include <sys/disk.h>
 #define BLKGETSIZE64 DIOCGMEDIASIZE
 #endif
+#include <limits.h>
 
 
 #ifdef WIN32
