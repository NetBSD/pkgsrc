$NetBSD: patch-src_base_PdfVariant.h,v 1.1 2017/09/25 22:26:27 joerg Exp $

Merge r1825.

--- src/base/PdfVariant.h.orig	2017-09-25 13:20:57.927586504 +0000
+++ src/base/PdfVariant.h
@@ -513,7 +513,7 @@ class PODOFO_API PdfVariant {
      *  required to access the correct member of 
      *  the union UVariant.
      */
-    EPdfDataType m_eDataType;
+    pdf_int8 m_eDataType;
 
     // No touchy. Only for use by PdfVariant's internal tracking of the delayed
     // loading state. Use DelayedLoadDone() to test this if you need to.
@@ -574,7 +574,7 @@ EPdfDataType PdfVariant::GetDataType() c
 {
     DelayedLoad();
 
-    return m_eDataType;
+    return static_cast<EPdfDataType>(m_eDataType);
 }
 
 // -----------------------------------------------------
