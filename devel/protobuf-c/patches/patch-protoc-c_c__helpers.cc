$NetBSD: patch-protoc-c_c__helpers.cc,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/309
https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_helpers.cc.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_helpers.cc
@@ -177,7 +177,7 @@ string ToCamel(const string &name) {
 }
 
 string FullNameToLower(const string &full_name) {
-  vector<string> pieces;
+  std::vector<string> pieces;
   SplitStringUsing(full_name, ".", &pieces);
   string rv = "";
   for (unsigned i = 0; i < pieces.size(); i++) {
@@ -188,7 +188,7 @@ string FullNameToLower(const string &ful
   return rv;
 }
 string FullNameToUpper(const string &full_name) {
-  vector<string> pieces;
+  std::vector<string> pieces;
   SplitStringUsing(full_name, ".", &pieces);
   string rv = "";
   for (unsigned i = 0; i < pieces.size(); i++) {
@@ -199,7 +199,7 @@ string FullNameToUpper(const string &ful
   return rv;
 }
 string FullNameToC(const string &full_name) {
-  vector<string> pieces;
+  std::vector<string> pieces;
   SplitStringUsing(full_name, ".", &pieces);
   string rv = "";
   for (unsigned i = 0; i < pieces.size(); i++) {
@@ -214,7 +214,7 @@ void PrintComment (io::Printer* printer,
 {
    if (!comment.empty())
    {
-      vector<string> comment_lines;
+      std::vector<string> comment_lines;
       SplitStringUsing (comment, "\r\n", &comment_lines);
       printer->Print ("/*\n");
       for (int i = 0; i < comment_lines.size(); i++)
@@ -503,8 +503,8 @@ void SplitStringToIteratorUsing(const st
 
 void SplitStringUsing(const string& full,
                       const char* delim,
-                      vector<string>* result) {
-  std::back_insert_iterator< vector<string> > it(*result);
+                      std::vector<string>* result) {
+  std::back_insert_iterator< std::vector<string> > it(*result);
   SplitStringToIteratorUsing(full, delim, it);
 }
 
@@ -559,7 +559,7 @@ static int CEscapeInternal(const char* s
 }
 string CEscape(const string& src) {
   const int dest_length = src.size() * 4 + 1; // Maximum possible expansion
-  scoped_array<char> dest(new char[dest_length]);
+  std::unique_ptr<char[]> dest(new char[dest_length]);
   const int len = CEscapeInternal(src.data(), src.size(),
                                   dest.get(), dest_length, false);
   GOOGLE_DCHECK_GE(len, 0);
