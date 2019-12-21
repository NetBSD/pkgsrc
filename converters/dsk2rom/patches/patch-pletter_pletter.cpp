$NetBSD: patch-pletter_pletter.cpp,v 1.2 2019/12/21 23:30:21 joerg Exp $

Add missing includes.
pletter is called from C code.

--- pletter/pletter.cpp.orig	2007-05-27 11:18:42.000000000 +0000
+++ pletter/pletter.cpp
@@ -9,6 +9,9 @@
 
 */
 
+#include <cstdlib>
+#include <cstring>
+#include <cstdio>
 #include <string>
 using namespace std;
 
@@ -306,7 +309,7 @@ int main(int argc, char *argv[]) {
 
 //-----------------------------------------------------------------------------
 
-void pletter( unsigned char*  input,  int  input_length,
+extern "C" void pletter( unsigned char*  input,  int  input_length,
 	      unsigned char** output, int* output_length,
 	      int pletmode  )
 {
