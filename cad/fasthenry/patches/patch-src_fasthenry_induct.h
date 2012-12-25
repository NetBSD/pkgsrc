$NetBSD: patch-src_fasthenry_induct.h,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/induct.h.orig	2004-08-03 22:19:39.000000000 +0000
+++ src/fasthenry/induct.h
@@ -654,4 +654,12 @@ extern int realComputePsi();
 /* SHELLS preconditioner shift */
 double shift_mutual();
 
+void make_equiv(NODES *orignode, NODES*realnode);
+void makegrids(SYS *indsys, CX *Im, int column, int freq_num);
+void dumpROMequiv_circuit(FILE *fp, double **Ar, double **Br, double **Cr,
+    double **Dr, int size, int numinp, int numout, char *title, char *suffix,
+    SYS *indsys);
+void mulMatUp(ssystem *sys);
+void put_in_table(FILAMENT *fil_j, FILAMENT *fil_m, int whperp, double mutterm, double *dims, int dim_count, Table **lastptr, int num_dims);
+
 #endif
