$NetBSD: patch-src_fasthenry_barnoldi.c,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/barnoldi.c.orig	2012-12-25 16:13:50.000000000 +0000
+++ src/fasthenry/barnoldi.c
@@ -458,14 +458,9 @@ dumpROM(fp, Ar, Br, Cr, Dr, size, numinp
  *
  *****************************************************************************/
 
-dumpROMequiv_circuit(fp, Ar, Br, Cr, Dr, size, numinp, numout, title, suffix,
-                     indsys)
-  FILE *fp;
-  double **Ar, **Br, **Cr, **Dr;
-  int size, numinp, numout;
-  char *title;
-  char *suffix;
-  SYS *indsys;
+void dumpROMequiv_circuit(FILE *fp, double **Ar, double **Br, double **Cr,
+    double **Dr, int size, int numinp, int numout, char *title, char *suffix,
+    SYS *indsys)
 {
   
   int i,j;
