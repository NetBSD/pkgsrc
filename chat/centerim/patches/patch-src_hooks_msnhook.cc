$NetBSD: patch-src_hooks_msnhook.cc,v 1.1 2013/03/02 18:20:19 joerg Exp $

--- src/hooks/msnhook.cc.orig	2013-03-01 12:43:38.000000000 +0000
+++ src/hooks/msnhook.cc
@@ -684,7 +684,7 @@ void msncallbacks::gotBuddyListInfo(MSN:
 
     mhook.setautostatus(mhook.manualstatus);
     mhook.timer_ping = timer_current;
-    mhook.log(abstracthook::logLogged);
+    mhook.log(msnhook::logLogged);
     face.update();
 }
 
@@ -883,7 +883,7 @@ void msncallbacks::closingConnection(MSN
 		clist.setoffline(msn);
 
 		mhook.fonline = false;
-		mhook.log(abstracthook::logDisconnected);
+		mhook.log(msnhook::logDisconnected);
 
 		face.update();
 	    }
