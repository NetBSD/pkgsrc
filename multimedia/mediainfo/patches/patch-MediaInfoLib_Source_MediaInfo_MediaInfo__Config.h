$NetBSD: patch-MediaInfoLib_Source_MediaInfo_MediaInfo__Config.h,v 1.2 2020/02/28 12:16:45 bsiegert Exp $

Avoid CS pollution from sys/regset.h on SunOS.

--- MediaInfoLib/Source/MediaInfo/MediaInfo_Config.h.orig	2020-02-28 11:50:05.265436338 +0000
+++ MediaInfoLib/Source/MediaInfo/MediaInfo_Config.h
@@ -30,6 +30,9 @@
 #include "ZenLib/InfoMap.h"
 #include <set>
 #include <bitset>
+#ifdef __sun
+#undef CS
+#endif
 using namespace ZenLib;
 using std::vector;
 using std::string;
