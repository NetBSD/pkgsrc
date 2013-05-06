$NetBSD: patch-fbreader_src_fbreader_FBView.cpp,v 1.1 2013/05/06 15:04:55 joerg Exp $

--- fbreader/src/fbreader/FBView.cpp.orig	2013-05-04 15:09:39.000000000 +0000
+++ fbreader/src/fbreader/FBView.cpp
@@ -18,6 +18,7 @@
  */
 
 #include <cmath>
+#include <cstdlib>
 #include <algorithm>
 
 #include <ZLUnicodeUtil.h>
