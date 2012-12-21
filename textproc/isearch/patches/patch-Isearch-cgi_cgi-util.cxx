$NetBSD: patch-Isearch-cgi_cgi-util.cxx,v 1.1 2012/12/21 10:29:46 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- Isearch-cgi/cgi-util.cxx~	1998-05-12 16:48:05.000000000 +0000
+++ Isearch-cgi/cgi-util.cxx
@@ -61,7 +61,7 @@ void CGIAPP::GetInput() {
   CHR *meth, *p, *query=(CHR*)NULL;
 
   if ((meth = (char *)getenv("REQUEST_METHOD"))==NULL) {
-    cout << "Unable to get request_method" << endl;
+    std::cout << "Unable to get request_method" << std::endl;
     exit(1);
   }
   if (!strcmp(meth,"POST")) {
@@ -73,10 +73,10 @@ void CGIAPP::GetInput() {
       query = (char *)getenv("QUERY_STRING");
       Method=GET;
     } else {
-      cout << "This program is to be referenced with a METHOD of POST or GET.\n";
-      cout << "If you don't understand this, see this ";
-      cout << "<A HREF=\"http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/";
-      cout << "Docs/fill-out-forms/overview.html\">forms overview</A>" << endl;
+      std::cout << "This program is to be referenced with a METHOD of POST or GET.\n";
+      std::cout << "If you don't understand this, see this ";
+      std::cout << "<A HREF=\"http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/";
+      std::cout << "Docs/fill-out-forms/overview.html\">forms overview</A>" << std::endl;
       exit (1);
     }
   }
@@ -84,7 +84,7 @@ void CGIAPP::GetInput() {
   if (Method==POST) {
     entry_count=0;
     for (x = 0; ContentLen>0; x++) {
-      cin.getline(temp1,ContentLen+1,'&');
+      std::cin.getline(temp1,ContentLen+1,'&');
       entry_count++;
       len=strlen(temp1);
       ContentLen=ContentLen-(len+1);
@@ -184,7 +184,7 @@ CGIAPP::CGIAPP() {
 void CGIAPP::Display() {
   INT x;
   for (x=0;x<entry_count;x++) {
-    cout << name[x] << " = " << value[x] << "<br>\n";
+    std::cout << name[x] << " = " << value[x] << "<br>\n";
   }
 }
 
