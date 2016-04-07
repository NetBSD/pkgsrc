$NetBSD: patch-src_hugin1_base__wx_platform.cpp,v 1.1 2016/04/07 19:23:26 adam Exp $

Re-order includes to fix building.

--- src/hugin1/base_wx/platform.cpp.orig	2016-02-19 22:26:02.000000000 +0000
+++ src/hugin1/base_wx/platform.cpp
@@ -24,9 +24,9 @@
  *
  */
 
-#include "platform.h"
 
 #include <hugin_utils/utils.h>
+#include "platform.h"
 
 #if defined __WXMAC__ || defined __WXOSX_COCOA__
 
