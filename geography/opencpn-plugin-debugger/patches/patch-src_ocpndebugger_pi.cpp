$NetBSD: patch-src_ocpndebugger_pi.cpp,v 1.1 2017/06/01 10:26:17 bouyer Exp $

64bit time_t fix

--- src/ocpndebugger_pi.cpp.orig	2017-06-01 12:14:55.978172546 +0200
+++ src/ocpndebugger_pi.cpp	2017-06-01 12:20:34.836463280 +0200
@@ -173,7 +173,7 @@
             _T("Cog: %f, Hdm: %f, Hdt: %f, Lat: %f, Lon: %f, ")
             _T("Sog: %f, Var: %f, nSats: %d, Fixtime: %d\n"),
             pfix.Cog, pfix.Hdm, pfix.Hdt, pfix.Lat, pfix.Lon, pfix.Sog,
-            pfix.Var, pfix.nSats, pfix.FixTime);
+            pfix.Var, pfix.nSats, (int)pfix.FixTime);
         m_pOpenCPNDebuggerDialog->SetNMEAEvent(msg);
     }
 }
