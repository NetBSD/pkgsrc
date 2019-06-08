$NetBSD: patch-plugins_paint_xp_AbiPaint.cpp,v 1.2 2019/06/08 10:40:53 rillig Exp $

* Fix seg fault.

--- plugins/paint/xp/AbiPaint.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/paint/xp/AbiPaint.cpp
@@ -177,6 +177,9 @@ static DECLARE_ABI_PLUGIN_METHOD(specify
 
 	// Get a frame in case we need to show an error message
 	XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
+	if (pFrame == NULL) {
+	  return false;
+	}
 
 	{
 		const char * szDescList[3];
@@ -254,6 +257,10 @@ static DECLARE_ABI_PLUGIN_METHOD(saveAsB
 {
 	// Get a frame (for error messages) and (to) get the current view that the user is in.
 	XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
+	if (pFrame == NULL) {
+	  g_varning("paint saveAsBmp: getLastFocussedFrame returned NULL\n");
+	  return false;
+	}
 	FV_View* pView = static_cast<FV_View*>(pFrame->getCurrentView());
 
 	char *szTempFileName = NULL;
