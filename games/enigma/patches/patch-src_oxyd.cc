$NetBSD: patch-src_oxyd.cc,v 1.2 2019/11/11 22:03:01 maya Exp $

Fix name conflict.

--- src/oxyd.cc.orig	2014-12-19 21:24:38.000000000 +0000
+++ src/oxyd.cc
@@ -125,7 +125,7 @@ namespace 
         }
     }
 
-    GridLoc to_gridloc (const SignalLocation &a)
+    GridLoc to_gridloc2 (const SignalLocation &a)
     {
         assert (a.getGridType() >= GridType_First &&
                 a.getGridType() <= GridType_Last);
@@ -652,8 +652,8 @@ void OxydLoader::connect_signals () 
         int nrec = level.getNumRecipients(sender);
         for (int irec=0; irec<nrec; ++irec) {
             SignalLocation recipient = level.getRecipient(sender, irec);
-            GridLoc src = ::to_gridloc(sender);
-            GridLoc dst = ::to_gridloc(recipient);
+            GridLoc src = ::to_gridloc2(sender);
+            GridLoc dst = ::to_gridloc2(recipient);
             AddSignal (src, dst, "signal");
         }
     }
