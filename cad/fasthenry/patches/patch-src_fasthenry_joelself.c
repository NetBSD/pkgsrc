$NetBSD: patch-src_fasthenry_joelself.c,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/joelself.c.orig	2012-12-25 16:34:10.000000000 +0000
+++ src/fasthenry/joelself.c
@@ -682,13 +682,7 @@ Table ***ret_lastptr, **a_table;
   return 0;
 }
       
-put_in_table(fil_j, fil_m, whperp, mutterm, dims, dim_count, lastptr, num_dims)
-FILAMENT *fil_j, *fil_m;
-int whperp;
-double mutterm;
-double *dims;
-int dim_count, num_dims;
-Table **lastptr;
+void put_in_table(FILAMENT *fil_j, FILAMENT *fil_m, int whperp, double mutterm, double *dims, int dim_count, Table **lastptr, int num_dims)
 {
   Table *entry;
   int i;
