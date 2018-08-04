$NetBSD: patch-protoc-c_c__generator.cc,v 1.1 2018/08/04 21:36:16 minskim Exp $

https://github.com/protobuf-c/protobuf-c/pull/309
https://github.com/protobuf-c/protobuf-c/pull/328

--- protoc-c/c_generator.cc.orig	2017-08-05 21:41:36.000000000 +0000
+++ protoc-c/c_generator.cc
@@ -80,13 +80,13 @@ namespace c {
 //   "foo=bar,baz,qux=corge"
 // parses to the pairs:
 //   ("foo", "bar"), ("baz", ""), ("qux", "corge")
-void ParseOptions(const string& text, vector<pair<string, string> >* output) {
-  vector<string> parts;
+  void ParseOptions(const string& text, std::vector<std::pair<string, string> >* output) {
+  std::vector<string> parts;
   SplitStringUsing(text, ",", &parts);
 
   for (unsigned i = 0; i < parts.size(); i++) {
     string::size_type equals_pos = parts[i].find_first_of('=');
-    pair<string, string> value;
+    std::pair<string, string> value;
     if (equals_pos == string::npos) {
       value.first = parts[i];
       value.second = "";
@@ -105,7 +105,7 @@ bool CGenerator::Generate(const FileDesc
                             const string& parameter,
                             OutputDirectory* output_directory,
                             string* error) const {
-  vector<pair<string, string> > options;
+  std::vector<std::pair<string, string> > options;
   ParseOptions(parameter, &options);
 
   // -----------------------------------------------------------------
@@ -149,7 +149,7 @@ bool CGenerator::Generate(const FileDesc
 
   // Generate header.
   {
-    scoped_ptr<io::ZeroCopyOutputStream> output(
+    std::unique_ptr<io::ZeroCopyOutputStream> output(
       output_directory->Open(basename + ".h"));
     io::Printer printer(output.get(), '$');
     file_generator.GenerateHeader(&printer);
@@ -157,7 +157,7 @@ bool CGenerator::Generate(const FileDesc
 
   // Generate cc file.
   {
-    scoped_ptr<io::ZeroCopyOutputStream> output(
+    std::unique_ptr<io::ZeroCopyOutputStream> output(
       output_directory->Open(basename + ".c"));
     io::Printer printer(output.get(), '$');
     file_generator.GenerateSource(&printer);
