$NetBSD: patch-src_hb-coretext.h,v 1.4 2015/11/24 08:20:51 wiz Exp $

Fix building on OS X.
https://github.com/behdad/harfbuzz/issues/183

--- src/hb-coretext.h.orig	2015-11-23 19:57:54.000000000 +0000
+++ src/hb-coretext.h
@@ -30,12 +30,8 @@
 #include "hb.h"
 
 #include <TargetConditionals.h>
-#if TARGET_OS_IPHONE
 #  include <CoreText/CoreText.h>
 #  include <CoreGraphics/CoreGraphics.h>
-#else
-#  include <ApplicationServices/ApplicationServices.h>
-#endif
 
 HB_BEGIN_DECLS
 
