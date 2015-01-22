$NetBSD: patch-src_crashprint.cpp,v 1.1 2015/01/22 12:34:15 bouyer Exp $

backtrace support is linux-only for now

--- src/crashprint.cpp.orig	2015-01-20 16:46:17.000000000 +0000
+++ src/crashprint.cpp	2015-01-20 16:46:24.000000000 +0000
@@ -76,6 +76,7 @@
 // general functions
 
 void wxCrashPrint::Report () {
+#if defined(__linux__)
     wxString appname = wxTheApp->GetAppName();
 
     // get the backtrace with symbols
@@ -136,5 +137,5 @@
             wxPrintf (_T("%s\n"), lines[i].c_str());
         }
     }
-
+#endif
 }
