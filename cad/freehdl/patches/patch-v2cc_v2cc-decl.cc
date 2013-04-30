$NetBSD: patch-v2cc_v2cc-decl.cc,v 1.1 2013/04/30 22:13:57 joerg Exp $

--- v2cc/v2cc-decl.cc.orig	2013-04-30 20:28:00.000000000 +0000
+++ v2cc/v2cc-decl.cc
@@ -1900,12 +1900,12 @@ m_emit_hdr (pIIR_ScalarSubtype sst, stri
       str += "class " + qid(decl, rstack, INFO) + ":public float_info_base{\n" +
 	"public:\n" +
 	"   " + qid(decl, rstack, INFO) + "():float_info_base(" + 
-	to_string(range.left) + ","+ to_string(range.right) + "," + 
-	to_string(min(range.left,range.right)) + "," + to_string(max(range.left, range.right)) + ") {};\n" + 
-	"   static floatingpoint low() { return " + to_string(min(range.left, range.right)) + "; }\n" +
-	"   static floatingpoint high() { return " + to_string(max(range.left, range.right)) + "; }\n" +
-	"   static floatingpoint left() { return " + to_string(range.left) + "; }\n" +
-	"   static floatingpoint right() { return " + to_string(range.right) + "; }\n" + 
+	::to_string(range.left) + ","+ ::to_string(range.right) + "," + 
+	::to_string(min(range.left,range.right)) + "," + ::to_string(max(range.left, range.right)) + ") {};\n" + 
+	"   static floatingpoint low() { return " + ::to_string(min(range.left, range.right)) + "; }\n" +
+	"   static floatingpoint high() { return " + ::to_string(max(range.left, range.right)) + "; }\n" +
+	"   static floatingpoint left() { return " + ::to_string(range.left) + "; }\n" +
+	"   static floatingpoint right() { return " + ::to_string(range.right) + "; }\n" + 
 	"};\n";
     } else {
       // Integer info class definition with non static bounds (i.e.,
