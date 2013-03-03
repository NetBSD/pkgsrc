$NetBSD: patch-calma_CalmaRdcl.c,v 1.1 2013/03/03 01:11:10 joerg Exp $

--- calma/CalmaRdcl.c.orig	2013-03-02 22:21:58.000000000 +0000
+++ calma/CalmaRdcl.c
@@ -46,6 +46,8 @@ static char rcsid[] __attribute__ ((unus
 #include "calma/calmaInt.h"
 #include "calma/calma.h"
 
+void calmaReadError(char *format, ...);
+
 int calmaNonManhattan;
 
 extern void CIFPaintCurrent();
@@ -53,7 +55,7 @@ extern void CIFPaintCurrent();
 extern HashTable calmaDefInitHash;
 
 /* forward declarations */
-bool calmaElementSref();
+void calmaElementSref();
 bool calmaParseElement();
 
 /* Structure used when flattening the GDS hierarchy on read-in */
@@ -520,7 +522,7 @@ calmaParseElement(pnsrefs, pnpaths)
  * ----------------------------------------------------------------------------
  */
 
-bool
+void
 calmaElementSref()
 {
     int nbytes, rtype, cols, rows, nref, n, i, savescale;
$NetBSD: patch-calma_CalmaRdcl.c,v 1.1 2013/03/03 01:11:10 joerg Exp $

--- calma/CalmaRdcl.c.orig	2013-03-02 22:21:58.000000000 +0000
+++ calma/CalmaRdcl.c
@@ -46,6 +46,8 @@ static char rcsid[] __attribute__ ((unus
 #include "calma/calmaInt.h"
 #include "calma/calma.h"
 
+void calmaReadError(char *format, ...);
+
 int calmaNonManhattan;
 
 extern void CIFPaintCurrent();
@@ -53,7 +55,7 @@ extern void CIFPaintCurrent();
 extern HashTable calmaDefInitHash;
 
 /* forward declarations */
-bool calmaElementSref();
+void calmaElementSref();
 bool calmaParseElement();
 
 /* Structure used when flattening the GDS hierarchy on read-in */
@@ -520,7 +522,7 @@ calmaParseElement(pnsrefs, pnpaths)
  * ----------------------------------------------------------------------------
  */
 
-bool
+void
 calmaElementSref()
 {
     int nbytes, rtype, cols, rows, nref, n, i, savescale;
