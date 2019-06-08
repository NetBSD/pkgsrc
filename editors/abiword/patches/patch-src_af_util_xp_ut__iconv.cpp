$NetBSD: patch-src_af_util_xp_ut__iconv.cpp,v 1.2 2019/06/08 10:40:53 rillig Exp $

* NetBSD uses citrus iconv that has UCS-4

--- src/af/util/xp/ut_iconv.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/xp/ut_iconv.cpp
@@ -267,9 +267,11 @@ const char * ucs4Internal ()
 #elif defined(_LIBICONV_H)
   // libiconv seems to prefer UCS-4-INTERNAL to UCS-4BE and UCS-4LE
   return "UCS-4-INTERNAL";
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__)
   // we special case the BSDs since spelling just doesn't work
   return "UCS4";
+#elif defined(__NetBSD__)
+  return "UCS-4";
 #else
   // general case, found by hub and dom
 	if (s_ucs4_internal == 0) 
