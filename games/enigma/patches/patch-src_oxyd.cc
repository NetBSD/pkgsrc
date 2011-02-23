$NetBSD: patch-src_oxyd.cc,v 1.1 2011/02/23 10:20:26 adam Exp $

Fix name conflict.

--- src/oxyd.cc.orig	2011-02-22 13:24:27.000000000 +0000
+++ src/oxyd.cc
@@ -130,7 +130,7 @@ namespace 
         }
     }
 
-    GridLoc to_gridloc (const SignalLocation &a)
+    GridLoc to_gridloc2 (const SignalLocation &a)
     {
         assert (a.getGridType() >= GridType_First &&
                 a.getGridType() <= GridType_Last);
@@ -644,8 +644,8 @@ void OxydLoader::connect_signals () 
         int nrec = level.getNumRecipients(sender);
         for (int irec=0; irec<nrec; ++irec) {
             SignalLocation recipient = level.getRecipient(sender, irec);
-            GridLoc src = to_gridloc(sender);
-            GridLoc dst = to_gridloc(recipient);
+            GridLoc src = to_gridloc2(sender);
+            GridLoc dst = to_gridloc2(recipient);
             world::AddSignal (src, dst, "signal");
         }
     }
