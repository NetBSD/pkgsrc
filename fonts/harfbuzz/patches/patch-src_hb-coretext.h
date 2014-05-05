$NetBSD: patch-src_hb-coretext.h,v 1.1 2014/05/05 10:27:28 tron Exp $

Fix build under Mac OS X:

https://bugs.freedesktop.org/show_bug.cgi?id=78291

--- src/hb-coretext.h.orig	2014-03-21 17:29:34.000000000 +0000
+++ src/hb-coretext.h	2014-05-05 11:15:26.000000000 +0100
@@ -30,7 +30,7 @@
 #include "hb.h"
 
 #include <TargetConditionals.h>
-#if defined(TARGET_OS_IPHONE)
+#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
 #  include <CoreText/CoreText.h>
 #  include <CoreGraphics/CoreGraphics.h>
 #else
