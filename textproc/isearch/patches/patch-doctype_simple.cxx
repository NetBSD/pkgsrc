$NetBSD: patch-doctype_simple.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- doctype/simple.cxx~	1998-06-03 03:30:13.000000000 +0000
+++ doctype/simple.cxx
@@ -57,7 +57,7 @@ SIMPLE::SIMPLE(PIDBOBJ DbParent) : DOCTY
 }
 void SIMPLE::BeforeRset(const STRING& RecordSyntax) {
   if (RecordSyntax.Equals(HtmlRecordSyntax))
-    cout << "<pre>" << endl;
+    std::cout << "<pre>" << std::endl;
 }
 
 void SIMPLE::Present(const RESULT& ResultRecord, const STRING& ElementSet, 
@@ -90,7 +90,7 @@ void SIMPLE::Present(const RESULT& Resul
 
 void SIMPLE::AfterRset(const STRING& RecordSyntax) {
   if (RecordSyntax.Equals(HtmlRecordSyntax))
-    cout << "</pre>" << endl;
+    std::cout << "</pre>" << std::endl;
 }
 
 SIMPLE::~SIMPLE() {
