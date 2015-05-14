$NetBSD: patch-MediaInfoLib_Source_MediaInfo_MediaInfo__Config.h,v 1.1 2015/05/14 13:20:06 jperkin Exp $

Avoid CS pollution from sys/regset.h on SunOS.

--- MediaInfoLib/Source/MediaInfo/MediaInfo_Config.h.orig	2013-10-11 14:18:26.000000000 +0000
+++ MediaInfoLib/Source/MediaInfo/MediaInfo_Config.h
@@ -29,6 +29,9 @@
 #include "ZenLib/Translation.h"
 #include "ZenLib/InfoMap.h"
 #include <bitset>
+#ifdef __sun
+#undef CS
+#endif
 using namespace ZenLib;
 using std::vector;
 using std::string;
