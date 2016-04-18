$NetBSD: patch-src_text_fmt_xp_fv__FrameEdit.h,v 1.1 2016/04/18 15:29:50 jperkin Exp $

Avoid FS define on SunOS.

--- src/text/fmt/xp/fv_FrameEdit.h.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/text/fmt/xp/fv_FrameEdit.h
@@ -71,7 +71,7 @@ public:
 	void                  deleteFrame(fl_FrameLayout * pFL = NULL);
 	void                  setDragType(UT_sint32 x,UT_sint32 y, bool bDrawFrame);
 	bool                  getFrameStrings(UT_sint32 x, UT_sint32 y,
-					      fv_FrameStrings &FS,
+					      fv_FrameStrings &FString,
 					      fl_BlockLayout ** pCloseBL,
 					      fp_Page ** pPage);
 	fl_FrameLayout *      getFrameLayout(void) const
