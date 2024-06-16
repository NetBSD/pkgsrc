$NetBSD: patch-src_div__ext.c,v 1.1 2024/06/16 11:36:58 markd Exp $

From Fedora - fixes build with gcc14

--- src/div_ext.c	2022-03-11 08:33:43.000000000 -0700
+++ src/div_ext.c	2022-03-28 16:18:12.827629679 -0600
@@ -59,17 +59,17 @@ mpfi_div_ext (mpfi_ptr res1, mpfi_ptr re
       mpfr_init2 (tmp1, mpfi_get_prec(res1));
       mpfr_init2 (tmp2, mpfi_get_prec(res2));
       if ( mpfr_number_p (&(op2->left)) ) {
-        tmp = mpfr_div (&(tmp2), &(op1->right), &(op2->left), MPFI_RNDD);
+        tmp = mpfr_div (tmp2, &(op1->right), &(op2->left), MPFI_RNDD);
       }
       else { /* denominator has infinite left endpoint */
-        mpfr_set_zero (&(tmp2), 1);
+        mpfr_set_zero (tmp2, 1);
       }
 
       if ( mpfr_number_p (&(op2->right)) ) {
-        tmp = mpfr_div ( &(tmp1), &(op1->right), &(op2->right), MPFI_RNDU);
+        tmp = mpfr_div (tmp1, &(op1->right), &(op2->right), MPFI_RNDU);
       }
       else { /* denominator has infinite right endpoint */
-        mpfr_set_zero( &(tmp1), -1);
+        mpfr_set_zero(tmp1, -1);
       }
 
       mpfr_set_inf (&(res1->left), -1);
@@ -86,17 +86,17 @@ mpfi_div_ext (mpfi_ptr res1, mpfi_ptr re
       mpfr_init2 (tmp1, mpfi_get_prec(res1));
       mpfr_init2 (tmp2, mpfi_get_prec(res2));
       if ( mpfr_number_p (&(op2->left)) ) {
-        tmp = mpfr_div (&(tmp1), &(op1->left), &(op2->left), MPFI_RNDU);
+        tmp = mpfr_div (tmp1, &(op1->left), &(op2->left), MPFI_RNDU);
       }
       else { /* denominator has infinite left endpoint */
-        mpfr_set_zero (&(tmp1), -1);
+        mpfr_set_zero (tmp1, -1);
       }
 
       if ( mpfr_number_p (&(op2->right)) ) {
-        tmp = mpfr_div ( &(tmp2), &(op1->left), &(op2->right), MPFI_RNDD);
+        tmp = mpfr_div (tmp2, &(op1->left), &(op2->right), MPFI_RNDD);
       }
       else { /* denominator has infinite right endpoint */
-        mpfr_set_zero( &(tmp2), 1);
+        mpfr_set_zero(tmp2, 1);
       }
       mpfr_set_inf (&(res1->left), -1);
       mpfr_set (&(res1->right), tmp1, MPFI_RNDU);
