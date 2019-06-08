$NetBSD: patch-plugins_paint_xp_AbiGeneric.cpp,v 1.2 2019/06/08 10:40:53 rillig Exp $

If pFrame is NULL an image is obviously not selected.
Fixes seg fault.

--- plugins/paint/xp/AbiGeneric.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/paint/xp/AbiGeneric.cpp
@@ -297,6 +297,9 @@ bool isImageSelected (void)
 {
 	// Get the current view that the user is in.
 	XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
+	if (pFrame == NULL) {
+	  return false;
+	}
 	FV_View* pView = static_cast<FV_View*>(pFrame->getCurrentView());
 
     return (pView->getSelectedImage(NULL) != 0);
