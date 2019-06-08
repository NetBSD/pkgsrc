$NetBSD: patch-plugins_gimp_xp_AbiGimp.cpp,v 1.2 2019/06/08 10:40:53 rillig Exp $

* Fix seg fault.

--- plugins/gimp/xp/AbiGimp.cpp.orig	2013-12-23 02:37:58.000000000 +0000
+++ plugins/gimp/xp/AbiGimp.cpp
@@ -249,6 +249,10 @@ AbiGimp_invoke(AV_View* /*v*/, EV_EditMe
 {
     // Get the current view that the user is in.
     XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
+    if (pFrame == NULL) {
+      UT_DEBUGMSG(("Gimp plugin: getLastFocussedFrame() returned NULL\n"));
+      return false;
+    }
     FV_View* pView = static_cast<FV_View*>(pFrame->getCurrentView());
 
 //
