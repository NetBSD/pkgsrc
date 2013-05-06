$NetBSD: patch-fbreader_src_fbreader_FBReaderActions.cpp,v 1.1 2013/05/06 15:04:55 joerg Exp $

--- fbreader/src/fbreader/FBReaderActions.cpp.orig	2013-05-04 15:09:20.000000000 +0000
+++ fbreader/src/fbreader/FBReaderActions.cpp
@@ -18,6 +18,7 @@
  */
 
 #include <algorithm>
+#include <cstdlib>
 
 #include <ZLStringUtil.h>
 #include <ZLDialogManager.h>
