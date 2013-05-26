$NetBSD: patch-qemu-xen_fpu_softfloat-specialize.h,v 1.1 2013/05/26 20:27:43 bouyer Exp $

--- qemu-xen/fpu/softfloat-specialize.h.orig	2013-05-26 21:19:30.000000000 +0200
+++ qemu-xen/fpu/softfloat-specialize.h	2013-05-26 21:20:25.000000000 +0200
@@ -89,8 +89,8 @@
 #define floatx80_default_nan_low  LIT64( 0xC000000000000000 )
 #endif
 
-const floatx80 floatx80_default_nan = make_floatx80(floatx80_default_nan_high,
-                                                    floatx80_default_nan_low);
+const floatx80 floatx80_default_nan = { .high = floatx80_default_nan_high,
+                                        .low =  floatx80_default_nan_low};
 
 /*----------------------------------------------------------------------------
 | The pattern for a default generated quadruple-precision NaN.  The `high' and
@@ -104,8 +104,8 @@
 #define float128_default_nan_low  LIT64( 0x0000000000000000 )
 #endif
 
-const float128 float128_default_nan = make_float128(float128_default_nan_high,
-                                                    float128_default_nan_low);
+const float128 float128_default_nan = {.high = float128_default_nan_high,
+                                       .low = float128_default_nan_low};
 
 /*----------------------------------------------------------------------------
 | Raises the exceptions specified by `flags'.  Floating-point traps can be
