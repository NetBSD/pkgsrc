$NetBSD: patch-doctype_soif.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - open the std namespace instead of using explicit "std" qualification

--- doctype/soif.cxx~	2000-09-06 21:33:31.000000000 +0000
+++ doctype/soif.cxx
@@ -7,11 +7,12 @@ Description: Harvest SOIF records (deriv
 Author:      Peter Valkenburg
 */
 
-#include <iostream.h>
-#include <ctype.h>
+#include <iostream>
+#include <cctype>
 #include "isearch.hxx"
 #include "soif.hxx"
 
+using namespace std;
 
 SOIF::SOIF(PIDBOBJ DbParent) : DOCTYPE(DbParent) {
 }
