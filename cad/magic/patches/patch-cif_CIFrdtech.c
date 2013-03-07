$NetBSD: patch-cif_CIFrdtech.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- cif/CIFrdtech.c.orig	2013-03-02 22:29:11.000000000 +0000
+++ cif/CIFrdtech.c
@@ -39,6 +39,7 @@ static char rcsid[] __attribute__ ((unus
 #include "cif/CIFread.h"
 #include "calma/calmaInt.h"
 #include "utils/malloc.h"
+#include "cif/cif.h"
 
 /* Pointer to a list of all the CIF-reading styles: */
 
@@ -1181,17 +1182,15 @@ cifParseCalmaNums(str, numArray, numNums
  * ----------------------------------------------------------------------------
  */
 
-int
-CIFTechInputScale(n, d, opt)
-    int n, d;
-    bool opt;
+void
+CIFTechInputScale(int n, int d, bool opt)
 {
     CIFReadStyle *istyle = cifCurReadStyle;
     CIFReadLayer *cl;
     CIFOp *op;
     int lmult, i, lgcf;
 
-    if (istyle == NULL) return 0;
+    if (istyle == NULL) return;
 
     /* fprintf(stderr, "CIF input style %s:\n", istyle->crs_name); */
 
@@ -1244,6 +1243,5 @@ CIFTechInputScale(n, d, opt)
 		    op->co_distance /= lmult;
 	}
     }
-    return lmult;
 }
 
