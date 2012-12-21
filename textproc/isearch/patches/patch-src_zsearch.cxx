$NetBSD: patch-src_zsearch.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- src/zsearch.cxx~	2000-10-24 18:40:36.000000000 +0000
+++ src/zsearch.cxx
@@ -91,7 +91,7 @@ int main(int argc, char** argv) {
     fprintf(stderr,"              # [fieldname/]searchterm[*][:n]\n");
     fprintf(stderr,"              # Prefix with fieldname/ for fielded searching.\n");
     fprintf(stderr,"              # Append * for right truncation.\n");
-    //    cout << "                        // Append ~ for soundex search." << endl;
+    //    cout << "                        // Append ~ for soundex search." << std::endl;
     fprintf(stderr,"              # Append :n for term weighting (default=1).\n");
     fprintf(stderr,"              # (Use negative values to lower rank.)\n");
     fprintf(stderr,"Examples: zsearch -d POETRY truth \"beaut*\" urn:2\n");
@@ -286,13 +286,13 @@ int main(int argc, char** argv) {
   }
 
   if (Error) {
-    cout << "\t<isearch:search status=\"Error\" dbname=\"" << DBName
-	 << "\">" << endl;
-    cout << "\t\t<isearch:error_block>" << endl;
-    cout << error_message;
-    cout << "\t\t</isearch:error_block>" << endl;
-    cout << "\t</search>" << endl;
-    cout << "</zsearch>" << endl;
+    std::cout << "\t<isearch:search status=\"Error\" dbname=\"" << DBName
+	 << "\">" << std::endl;
+    std::cout << "\t\t<isearch:error_block>" << std::endl;
+    std::cout << error_message;
+    std::cout << "\t\t</isearch:error_block>" << std::endl;
+    std::cout << "\t</search>" << std::endl;
+    std::cout << "</zsearch>" << std::endl;
     EXIT_ERROR;
   }
 
@@ -357,23 +357,23 @@ int main(int argc, char** argv) {
   }
 
   if (Error) {
-    cout << "\t<isearch:search status=\"Error\" dbname=\"" << DBName
-	 << "\">" << endl;
-    cout << "\t\t<isearch:error_block>" << endl;
-    cout << error_message;
-    cout << "\t\t</isearch:error_block>" << endl;
-    cout << "\t</isearch:search>" << endl;
-    cout << "</zsearch>" << endl;
+    std::cout << "\t<isearch:search status=\"Error\" dbname=\"" << DBName
+	 << "\">" << std::endl;
+    std::cout << "\t\t<isearch:error_block>" << std::endl;
+    std::cout << error_message;
+    std::cout << "\t\t</isearch:error_block>" << std::endl;
+    std::cout << "\t</isearch:search>" << std::endl;
+    std::cout << "</zsearch>" << std::endl;
     EXIT_ERROR;
   }
 
-  cout << "\t<isearch:query>" << QueryString << "</isearch:query>" << endl;
+  std::cout << "\t<isearch:query>" << QueryString << "</isearch:query>" << std::endl;
 
   if (Synonyms) {
     STRING S;
     squery.ExpandQuery();
     squery.GetTerm(&S);
-    cout << "\t<isearch:query type=\"expanded\">" << S << "</isearch:query>" << endl;
+    std::cout << "\t<isearch:query type=\"expanded\">" << S << "</isearch:query>" << std::endl;
   }
 
   if (BooleanAnd) {
@@ -424,7 +424,7 @@ int main(int argc, char** argv) {
       
       result.GetVKey(&ResultKey);
       printf("\t\t\t<isearch:result rank=\"%i\"",t);
-      cout << " docid=\"" << ResultKey << "\" ";
+      std::cout << " docid=\"" << ResultKey << "\" ";
       printf(" score=\"%i\"/>\n",
 	     prset->GetScaledScore(result.GetScore(), 100));
 
