$NetBSD: patch-src_irset.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - open the std namespace instead of using explicit "std" qualification

--- src/irset.cxx~	2000-10-24 18:42:20.000000000 +0000
+++ src/irset.cxx
@@ -70,6 +70,7 @@ Author:		Nassib Nassar, nrn@cnidr.org
 #include "squery.hxx"
 #include "dtreg.hxx"
 
+using namespace std;
 
 int 
 IrsetIndexCompare(const void* x, const void* y) 
