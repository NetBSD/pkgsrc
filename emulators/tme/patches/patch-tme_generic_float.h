$NetBSD: patch-tme_generic_float.h,v 1.1 2015/09/13 15:08:09 joerg Exp $

--- tme/generic/float.h.orig	2015-09-03 14:45:16.000000000 +0000
+++ tme/generic/float.h
@@ -308,13 +308,13 @@ tme_float_assert_formats(_tme_const stru
 
 /* these return the exponents of values in the IEEE 754 formats: */
 #define tme_float_value_ieee754_exponent_single(x) \
-  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_single, 0x7f800000)
+  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_single, 0x7f800000U)
 #define tme_float_value_ieee754_exponent_double(x) \
-  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_double.tme_value64_uint32_hi, 0x7ff00000)
+  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_double.tme_value64_uint32_hi, 0x7ff00000U)
 #define tme_float_value_ieee754_exponent_extended80(x) \
-  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_extended80.tme_float_ieee754_extended80_sexp, 0x7fff)
+  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_extended80.tme_float_ieee754_extended80_sexp, 0x7fffU)
 #define tme_float_value_ieee754_exponent_quad(x) \
-  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_quad.tme_float_ieee754_quad_hi.tme_value64_uint32_hi, 0x7fff0000)
+  TME_FIELD_MASK_EXTRACTU((x)->tme_float_value_ieee754_quad.tme_float_ieee754_quad_hi.tme_value64_uint32_hi, 0x7fff0000U)
 
 /* these return a bitwise-or of the fraction bits in values in the
    IEEE 754 formats (and, for the IEEE 754 80-bit extended precision
