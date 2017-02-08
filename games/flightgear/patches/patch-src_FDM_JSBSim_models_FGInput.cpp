$NetBSD: patch-src_FDM_JSBSim_models_FGInput.cpp,v 1.1 2017/02/08 00:03:30 joerg Exp $

--- src/FDM/JSBSim/models/FGInput.cpp.orig	2017-01-09 15:20:24.952109589 +0000
+++ src/FDM/JSBSim/models/FGInput.cpp
@@ -161,7 +161,7 @@ bool FGInput::Run(bool Holding)
           } else {
             socket->Reply("Must be in HOLD to search properties\n");
           }
-        } else if (node > 0) {
+        } else if (node) {
           ostringstream buf;
           buf << argument << " = " << setw(12) << setprecision(6) << node->getDoubleValue() << endl;
           socket->Reply(buf.str());
