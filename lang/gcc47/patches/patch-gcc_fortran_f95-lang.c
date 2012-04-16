$NetBSD: patch-gcc_fortran_f95-lang.c,v 1.1.1.1 2012/04/16 04:27:18 sbd Exp $

No NetBSD the 'cabs' and 'cabsf' functions are are __RENAME so that
thay have '__c99_' prefixes.

--- gcc/fortran/f95-lang.c.orig	2012-01-17 14:34:37.000000000 +0000
+++ gcc/fortran/f95-lang.c
@@ -819,10 +819,17 @@ gfc_init_builtin_functions (void)
 
   gfc_define_builtin ("__builtin_cabsl", func_clongdouble_longdouble, 
 		      BUILT_IN_CABSL, "cabsl", ATTR_CONST_NOTHROW_LEAF_LIST);
+#if defined(__NetBSD__)
+  gfc_define_builtin ("__builtin_cabs", func_cdouble_double, 
+		     BUILT_IN_CABS, "__c99_cabs", ATTR_CONST_NOTHROW_LEAF_LIST);
+  gfc_define_builtin ("__builtin_cabsf", func_cfloat_float, 
+		     BUILT_IN_CABSF, "__c99_cabsf", ATTR_CONST_NOTHROW_LEAF_LIST);
+#else
   gfc_define_builtin ("__builtin_cabs", func_cdouble_double, 
 		      BUILT_IN_CABS, "cabs", ATTR_CONST_NOTHROW_LEAF_LIST);
   gfc_define_builtin ("__builtin_cabsf", func_cfloat_float, 
 		      BUILT_IN_CABSF, "cabsf", ATTR_CONST_NOTHROW_LEAF_LIST);
+#endif
  
   gfc_define_builtin ("__builtin_copysignl", mfunc_longdouble[1], 
 		      BUILT_IN_COPYSIGNL, "copysignl",
