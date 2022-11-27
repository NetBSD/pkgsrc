$NetBSD: patch-tests_tstckintc.c,v 1.1 2022/11/27 03:17:13 mef Exp $

openscad-2021.01nb13 failed with math/mpfr-4.1.1
patch is supplied at  
 https://www.mpfr.org/mpfr-4.1.1/patch01
and this is one of piece for file to file from above
See:
 http://mail-index.netbsd.org/pkgsrc-users/2022/11/26/msg036540.html

--- mpfr-4.1.1-a/tests/tstckintc.c	2022-05-06 13:47:17.000000000 +0000
+++ ./tests/tstckintc.c	2022-11-23 11:45:26.836475987 +0000
@@ -295,14 +295,16 @@
 test_nan_inf_zero (void)
 {
   mpfr_ptr val;
+  mpfr_srcptr sval;  /* for compilation error checking */
   int sign;
   int kind;
 
   reset_stack ();
 
   val = new_mpfr (MPFR_PREC_MIN);
+  sval = val;
   mpfr_set_nan (val);
-  kind = (mpfr_custom_get_kind) (val);
+  kind = (mpfr_custom_get_kind) (sval);
   if (kind != MPFR_NAN_KIND)
     {
       printf ("mpfr_custom_get_kind error: ");
@@ -380,7 +382,8 @@
 dummy_set_si (long si)
 {
   mpfr_t x;
-  long * r = dummy_new ();
+  mpfr_srcptr px;  /* for compilation error checking */
+  long *r = dummy_new ();
   int i1, i2, i3, i4, i5;
 
   /* Check that the type "void *" can be used, like with the function.
@@ -405,7 +408,8 @@
   MPFR_ASSERTN (i5 == 1);
 
   mpfr_set_si (x, si, MPFR_RNDN);
-  r[0] = mpfr_custom_get_kind (x);
+  px = x;
+  r[0] = mpfr_custom_get_kind (px);
 
   /* Check that the type "void *" can be used in C, like with the function
      (forbidden in C++). Also check side effects. */
