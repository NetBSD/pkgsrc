$NetBSD: patch-zlibrary_text_src_area_ZLTextAreaStyle.cpp,v 1.1 2013/05/06 15:04:55 joerg Exp $

--- zlibrary/text/src/area/ZLTextAreaStyle.cpp.orig	2013-05-04 15:07:13.000000000 +0000
+++ zlibrary/text/src/area/ZLTextAreaStyle.cpp
@@ -18,6 +18,7 @@
  */
 
 #include <algorithm>
+#include <cstdlib>
 
 #include <ZLUnicodeUtil.h>
 #include <ZLPaintContext.h>
