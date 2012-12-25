$NetBSD: patch-doctype_dtconf.cxx,v 1.1 2012/12/25 18:50:17 dholland Exp $

Declare main's return type.

--- doctype/dtconf.cxx~	2000-08-15 03:30:51.000000000 +0000
+++ doctype/dtconf.cxx
@@ -64,6 +64,7 @@ Author:		Nassib Nassar, nrn@cnidr.org
 static char DtName[MAXDT][MAXSTR];
 static char DtFn[MAXDT][MAXSTR];
 
+int
 main() {
   printf("\nConfiguring Isearch for the following document types (see dtconf.inf):");
 
