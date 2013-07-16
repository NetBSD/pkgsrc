$NetBSD: patch-src_doc_PdfFontType1Base14.cpp,v 1.1 2013/07/16 21:28:43 joerg Exp $

--- src/doc/PdfFontType1Base14.cpp.orig	2010-10-21 17:09:00.000000000 +0000
+++ src/doc/PdfFontType1Base14.cpp
@@ -31,7 +31,7 @@ PdfFontType1Base14::PdfFontType1Base14(
                                         PdfVecObjects* pParent )
     : PdfFontSimple( pMetrics, pEncoding, pParent )
 {
-    InitBase14Font();
+    InitBase14Font( pMetrics );
 }
 
 // OC 13.08.2010 New:
@@ -39,7 +39,7 @@ PdfFontType1Base14::PdfFontType1Base14(
                                         PdfObject* pObject )
     : PdfFontSimple( pMetrics, pEncoding, pObject )
 {
-    InitBase14Font();
+    InitBase14Font( pMetrics );
 }
 
 PdfFontType1Base14::~PdfFontType1Base14()
@@ -52,12 +52,12 @@ PdfFontType1Base14::~PdfFontType1Base14(
 kausik : April 12th 2010
 This is the font dictionary. It gets added to the page resources dictionary of the pdf.
 */
-void PdfFontType1Base14::InitBase14Font( )
+void PdfFontType1Base14::InitBase14Font( PdfFontMetrics* pMetrics )
 {
     PdfVariant    var;
     
     this->GetObject()->GetDictionary().AddKey( PdfName::KeySubtype, PdfName("Type1"));
-    this->GetObject()->GetDictionary().AddKey("BaseFont", this->GetBaseFont() );
+    this->GetObject()->GetDictionary().AddKey("BaseFont", PdfName( pMetrics->GetFontname() ) );
 		 
     m_pEncoding->AddToDictionary( this->GetObject()->GetDictionary() ); // Add encoding key
 //	pDescriptor->GetDictionary().AddKey( "FontName", this->GetBaseFont() );
