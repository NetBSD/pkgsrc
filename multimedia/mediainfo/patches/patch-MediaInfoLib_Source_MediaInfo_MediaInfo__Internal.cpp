$NetBSD: patch-MediaInfoLib_Source_MediaInfo_MediaInfo__Internal.cpp,v 1.1 2025/11/23 23:13:21 wiz Exp $

SIGINT etc. are used even when _POSIX_PRIORITY_SCHEDULING is not defined.

--- MediaInfoLib/Source/MediaInfo/MediaInfo_Internal.cpp.orig	2025-11-23 23:11:01.344670767 +0000
+++ MediaInfoLib/Source/MediaInfo/MediaInfo_Internal.cpp
@@ -75,9 +75,9 @@
     #elif defined(_POSIX_PRIORITY_SCHEDULING)
         #include <sched.h>
         #include <unistd.h>
-        #include <signal.h>
     #endif //_POSIX_PRIORITY_SCHEDULING
     #include <ctime>
+    #include <signal.h>
 #endif
 using namespace ZenLib;
 using namespace std;
