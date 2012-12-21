$NetBSD: patch-src_zpresent.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

XXX: I strongly suspect the "exit;" below is an error.

--- src/zpresent.cxx~	2000-10-24 18:40:36.000000000 +0000
+++ src/zpresent.cxx
@@ -62,13 +62,13 @@ Author:		A. Warnock (warnock@awcubed.com
 
 void
 XmlBail(const STRING& DBName, const STRING& error_message) {
-    cout << "\t<isearch:present status=\"Error\" dbname=\"" << DBName
-	 << "\">" << endl;
-    cout << "\t\t<isearch:error_block>" << endl;
-    cout << error_message;
-    cout << "\t\t</isearch:error_block>" << endl;
-    cout << "\t</isearch:present>" << endl;
-    cout << "</zpresent>" << endl;
+    std::cout << "\t<isearch:present status=\"Error\" dbname=\"" << DBName
+	 << "\">" << std::endl;
+    std::cout << "\t\t<isearch:error_block>" << std::endl;
+    std::cout << error_message;
+    std::cout << "\t\t</isearch:error_block>" << std::endl;
+    std::cout << "\t</isearch:present>" << std::endl;
+    std::cout << "</zpresent>" << std::endl;
     exit;
 }
 
@@ -289,10 +289,10 @@ main(int argc, char** argv) {
     } else {
       error_message.Cat("\t\t\t\t<isearch:error_text>Record ");
       error_message.Cat("not found.</isearch:error_text>\n");
-      cout << "\t\t\t<isearch:result docid=\"" << RecordKey <<
+      std::cout << "\t\t\t<isearch:result docid=\"" << RecordKey <<
 	"\" status=\"Error\">\n";
-      cout << error_message;
-      cout << "\t\t\t</isearch:result>" << endl;
+      std::cout << error_message;
+      std::cout << "\t\t\t</isearch:result>" << std::endl;
     }
   }
 
