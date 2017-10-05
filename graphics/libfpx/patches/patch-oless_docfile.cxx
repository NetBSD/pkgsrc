$NetBSD: patch-oless_docfile.cxx,v 1.1.2.2 2017/10/05 02:08:51 spz Exp $
fix CVE-2017-12925
--- oless/docfile.cxx.orig	2017-10-03 18:06:20.000000000 +0000
+++ oless/docfile.cxx
@@ -49,6 +49,7 @@ SCODE DfFromLB(ILockBytes *plst,
     SCODE sc, scConv;
     CRootExposedDocFile *prpdf;
     CDFBasis *pdfb=NULL;
+    bool prpdf_Release_run = false;
 
     UNREFERENCED_PARM(pcid);
     olDebugOut((DEB_ITRACE, "In  DfFromLB(%p, %X, %lX, %p, %p, %p)\n",
@@ -71,9 +72,12 @@ SCODE DfFromLB(ILockBytes *plst,
     return scConv;
 
 EH_ppcInit:
-    prpdf->Release();
+    prpdf->Release(); //this also deletes pdfb
+    prpdf_Release_run = true;
 EH_pdfb:
-    delete pdfb;
+    if (!prpdf_Release_run) {
+        delete pdfb;
+    } 
 EH_Err:
     return sc;
 }
