$NetBSD: patch-rtrmgr_xorpsh__main.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rtrmgr/xorpsh_main.cc.orig	2012-07-03 16:31:20.000000000 +0000
+++ rtrmgr/xorpsh_main.cc
@@ -668,7 +668,7 @@ XorpShell::config_changed(uid_t user_id,
 	_router_cli->notify_user(response, /* urgent */ true);
 	// XXX it's not clear we can continue if this happens
     }
-    response == "";
+    response = "";
     if (!_ct->apply_deletions(user_id, deletions,
 			      /* this is not a provisional change */ false,
 			      response)) {
