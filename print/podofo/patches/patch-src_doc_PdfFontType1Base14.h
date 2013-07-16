$NetBSD: patch-src_doc_PdfFontType1Base14.h,v 1.1 2013/07/16 21:28:43 joerg Exp $

--- src/doc/PdfFontType1Base14.h.orig	2013-07-08 13:31:23.631273082 +0000
+++ src/doc/PdfFontType1Base14.h
@@ -66,7 +66,7 @@ class PdfFontType1Base14 : public PdfFon
     virtual void EmbedFontFile( PdfObject* pDescriptor );
 
  private:
-    void InitBase14Font();
+    void InitBase14Font( PdfFontMetrics* pMetrics );
 
 };
 
