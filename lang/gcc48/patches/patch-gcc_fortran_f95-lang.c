$NetBSD: patch-gcc_fortran_f95-lang.c,v 1.4 2014/11/28 09:57:32 obache Exp $

No NetBSD the 'cabs' and 'cabsf' functions are are __RENAME so that
thay have '__c99_' prefixes.

--- gcc/fortran/f95-lang.c.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/fortran/f95-lang.c
@@ -710,12 +710,21 @@ gfc_init_builtin_functions (void)
   gfc_define_builtin ("__builtin_truncf", mfunc_float[0],
 		      BUILT_IN_TRUNCF, "truncf", ATTR_CONST_NOTHROW_LEAF_LIST);
 
+#if defined(__NetBSD__)
+  gfc_define_builtin ("__builtin_cabs", func_cdouble_double, 
+		     BUILT_IN_CABS, "__c99_cabs", ATTR_CONST_NOTHROW_LEAF_LIST);
+  gfc_define_builtin ("__builtin_cabsf", func_cfloat_float, 
+		     BUILT_IN_CABSF, "__c99_cabsf", ATTR_CONST_NOTHROW_LEAF_LIST);
   gfc_define_builtin ("__builtin_cabsl", func_clongdouble_longdouble, 
-		      BUILT_IN_CABSL, "cabsl", ATTR_CONST_NOTHROW_LEAF_LIST);
+		      BUILT_IN_CABSL, "__c99_cabsl", ATTR_CONST_NOTHROW_LEAF_LIST);
+#else
   gfc_define_builtin ("__builtin_cabs", func_cdouble_double, 
 		      BUILT_IN_CABS, "cabs", ATTR_CONST_NOTHROW_LEAF_LIST);
   gfc_define_builtin ("__builtin_cabsf", func_cfloat_float, 
 		      BUILT_IN_CABSF, "cabsf", ATTR_CONST_NOTHROW_LEAF_LIST);
+  gfc_define_builtin ("__builtin_cabsl", func_clongdouble_longdouble, 
+		      BUILT_IN_CABSL, "cabsl", ATTR_CONST_NOTHROW_LEAF_LIST);
+#endif
  
   gfc_define_builtin ("__builtin_copysignl", mfunc_longdouble[1], 
 		      BUILT_IN_COPYSIGNL, "copysignl",
@@ -1069,6 +1078,13 @@ gfc_maybe_initialize_eh (void)
   using_eh_for_cleanups ();
 }
 
+#ifdef __OpenBSD__
+const char *
+fname_as_string(int pretty_p __attribute__((__unused__)))
+{
+	return NULL;
+}
+#endif
 
 #include "gt-fortran-f95-lang.h"
 #include "gtype-fortran.h"
