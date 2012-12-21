$NetBSD: patch-src_fct.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification

--- src/fct.cxx~	2001-11-21 07:02:03.000000000 +0000
+++ src/fct.cxx
@@ -5,8 +5,8 @@ Description:	Class FCT - Field Coordinat
 Author:		Nassib Nassar, nrn@cnidr.org
 @@@*/
 
-#include <stdlib.h>
-#include <iostream.h>
+#include <cstdlib>
+#include <iostream>
 
 #include "defs.hxx"
 #include "string.hxx"
@@ -103,7 +103,7 @@ void FCT::Read(PFILE fp) {
 	}
 }
 
-void FCT::Print(ostream& Os) const {
+void FCT::Print(std::ostream& Os) const {
 	FCTNODE* p = (FCTNODE*)(GetNodePtr(1));
 	while (p) {
 		Os << p->Fc;
@@ -120,7 +120,7 @@ void FCT::SubtractOffset(const GPTYPE Gp
 	}
 }
 
-ostream& operator<<(ostream& Os, const FCT& Fct) {
+std::ostream& operator<<(std::ostream& Os, const FCT& Fct) {
 	Fct.Print(Os);
 	return Os;
 }
