$NetBSD: patch-src_ClamAv.cc,v 1.1 2020/04/14 19:57:02 prlw1 Exp $

ClamAv restructured scan options flags from a single bitflag field
to a structure containing multiple bitflag fields.

--- src/ClamAv.cc.orig	2015-11-08 18:07:35.000000000 +0000
+++ src/ClamAv.cc
@@ -44,7 +44,10 @@ void Adapter::ClamAv::scan(Answer &answe
     // We assume that cl_*() functions used here are threadsafe.
 
     const char *virname = 0;
-    const int eScanResult = cl_scanfile(answer.fileName.c_str(), &virname, 0, engine, CL_SCAN_STDOPT);
+    struct cl_scan_options options;
+    memset(&options, 0, sizeof(options));
+    options.parse |= ~0; // enable all parsers
+    const int eScanResult = cl_scanfile(answer.fileName.c_str(), &virname, 0, engine, &options);
 
     switch (eScanResult) {
     case CL_CLEAN:
