$NetBSD: patch-src_FDM_JSBSim_input__output_FGScript.cpp,v 1.1 2017/02/08 00:03:30 joerg Exp $

--- src/FDM/JSBSim/input_output/FGScript.cpp.orig	2017-01-09 15:19:43.879132741 +0000
+++ src/FDM/JSBSim/input_output/FGScript.cpp
@@ -185,12 +185,12 @@ bool FGScript::LoadScript(string script,
   }
 
   // Now, read input spec if given.
-  if (input_element > 0) {
+  if (input_element) {
     FDMExec->GetInput()->Load(input_element);
   }
 
   // Now, read output spec if given.
-  if (output_element > 0) {
+  if (output_element) {
     string output_file = output_element->GetAttributeValue("file");
     if (output_file.empty()) {
       cerr << "No logging directives file was specified." << endl;
