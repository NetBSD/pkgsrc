$NetBSD: patch-doctype_oneline.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- doctype/oneline.cxx~	1996-12-21 00:40:40.000000000 +0000
+++ doctype/oneline.cxx
@@ -6,7 +6,7 @@ Description: class ONELINE - index docum
 Author:      Erik Scott, Scott Technologies, Inc.
 */
 
-#include <ctype.h>
+#include <cctype>
 #include "isearch.hxx"
 #include "oneline.hxx"
 
@@ -24,7 +24,7 @@ void ONELINE::ParseRecords(const RECORD&
   PFILE Fp = fopen (Fn, "rb");
   if (!Fp)
     {
-      cout << "Could not access '" << Fn << "'\n";
+      std::cout << "Could not access '" << Fn << "'\n";
       return;			// File not accessed
 
     }
