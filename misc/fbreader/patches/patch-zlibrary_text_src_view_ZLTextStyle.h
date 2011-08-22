$NetBSD: patch-zlibrary_text_src_view_ZLTextStyle.h,v 1.1 2011/08/22 11:24:07 wiz Exp $

Fix build with gcc-4.5.

--- zlibrary/text/src/view/ZLTextStyle.h.orig	2009-03-30 12:56:07.000000000 +0000
+++ zlibrary/text/src/view/ZLTextStyle.h
@@ -304,7 +304,7 @@ public:
 
 private:
 	ZLTextPositionIndicatorInfo(const ZLTextPositionIndicatorInfo&);
-	const ZLTextPositionIndicatorInfo operator = (const ZLTextPositionIndicatorInfo&);
+	const ZLTextPositionIndicatorInfo &operator = (const ZLTextPositionIndicatorInfo&);
 };
 
 class ZLTextStyleCollection {
