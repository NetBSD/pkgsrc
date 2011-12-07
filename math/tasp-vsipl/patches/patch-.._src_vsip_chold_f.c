$NetBSD: patch-.._src_vsip_chold_f.c,v 1.1 2011/12/07 15:17:00 joerg Exp $

--- ../src/vsip_chold_f.c.orig	2011-12-07 14:15:23.000000000 +0000
+++ ../src/vsip_chold_f.c
@@ -44,7 +44,7 @@ VI_cholesky_low_f(
       vsip_scalar_f *a_kk = A->block->array + A->block->rstride *(A->offset + k * (A->row_stride + A->col_stride));
       if(*a_kk <= 0){
           retval++;
-          return;
+          break;
       } else { 
          scale = sqrt((double)*a_kk);
       }
