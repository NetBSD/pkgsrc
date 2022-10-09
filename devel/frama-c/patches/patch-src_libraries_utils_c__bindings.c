$NetBSD: patch-src_libraries_utils_c__bindings.c,v 1.2 2022/10/09 07:02:47 tonio Exp $

sync ifdefs with reality

--- src/libraries/utils/c_bindings.c.orig	2022-06-21 00:00:00.000000000 +0000
+++ src/libraries/utils/c_bindings.c
@@ -34,18 +34,7 @@
 #include <stdint.h>
 #include <unistd.h>
 
-// Some BSD flavors do not implement all of C99
-#if defined(__NetBSD__)
-# include <ieeefp.h>
-# define FE_DOWNWARD FP_RM
-# define FE_UPWARD FP_RP
-# define FE_TONEAREST FP_RN
-# define FE_TOWARDZERO FP_RZ
-# define fegetround()	fpgetround()
-# define fesetround(RM)	fpsetround(RM)
-#else 
-# include <fenv.h>
-#endif
+#include <fenv.h>
 
 #include <float.h>
 #include <math.h>
