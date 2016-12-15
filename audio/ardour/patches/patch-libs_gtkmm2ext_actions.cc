$NetBSD: patch-libs_gtkmm2ext_actions.cc,v 1.1 2016/12/15 23:45:07 joerg Exp $

Use bool conversion, RefPtr doesn't compare to 0 in C++11 mode.

--- libs/gtkmm2ext/actions.cc.orig	2016-12-15 17:09:46.201195818 +0000
+++ libs/gtkmm2ext/actions.cc
@@ -401,7 +401,7 @@ ActionManager::get_action (const char* g
 	   gtkmm2.6, so we fall back to the C level.
 	*/
 
-	if (ui_manager == 0) {
+	if (!ui_manager) {
 		return RefPtr<Action> ();
 	}
 
