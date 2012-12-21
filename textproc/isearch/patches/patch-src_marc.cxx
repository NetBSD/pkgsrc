$NetBSD: patch-src_marc.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification
   - string constants are const char *

Avoid insecure use of tempnam().

--- src/marc.cxx.orig	1998-05-12 16:49:10.000000000 +0000
+++ src/marc.cxx
@@ -61,7 +61,7 @@ MARC::MARC(STRING & Data)
   c_data = Data.NewCString();
   c_len = Data.GetLength();
   if((c_rec = GetMARC(c_data,c_len,0)) == NULL) {
-    cerr << "Error parsing MARC record" << endl;
+    std::cerr << "Error parsing MARC record" << std::endl;
     return;
   }
   c_format = 0;
@@ -102,12 +102,12 @@ char fieldbuffer[FIELDBUFSIZE];
 char linebuffer[FIELDBUFSIZE];
 
 typedef struct {
-  char *label;
-  char *tags;
-  char *subfields;
-  char *beginpunct;
-  char *subfsep;
-  char *endpunct;
+  const char *label;
+  const char *tags;
+  const char *subfields;
+  const char *beginpunct;
+  const char *subfsep;
+  const char *endpunct;
   int  newfield;
   int  print_all;
   int  print_indicators;
@@ -194,9 +194,15 @@ MARC::GetPrettyBuffer(STRING *Buffer)
 {
   /*
   // Cheese, cheese, cheese;-)
-  char *tempfile = tempnam("/tmp", "marc");
+  char tempfile[32];
+  strcpy(tempfile, "/tmp/marcXXXXXX");
+  int tempfd = mkstemp(tempfile);
+  if (tempfd < 0) {
+    *Buffer = "MARC::GetPrettyBuffer() failed to open temp file";
+    return;
+  }
   FILE *fp;
-  if((fp = fopen(tempfile, "w")) == NULL) {
+  if((fp = fdopen(tempfd, "w")) == NULL) {
     *Buffer = "MARC::GetPrettyBuffer() failed to open temp file";
     return;
   }
@@ -381,7 +387,8 @@ char *
 format_field(MARC_FIELD *mf, DISP_FORMAT *format, CHR *buff, INT repeat)
 {
   MARC_SUBFIELD *subf;
-  register char *linend, *c;
+  register char *linend;
+  const register char *c;
   INT pos, count, ok=0;
 	
   linend = buff;
