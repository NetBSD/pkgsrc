$NetBSD: patch-plugins_ladspa__effect_calf_src_calf_fixed__point.h,v 1.1 2013/06/27 15:48:11 joerg Exp $

--- plugins/ladspa_effect/calf/src/calf/fixed_point.h.orig	2013-06-27 13:17:57.000000000 +0000
+++ plugins/ladspa_effect/calf/src/calf/fixed_point.h
@@ -216,7 +216,7 @@ public:
     }
 
     template<class U, int UseBits> 
-    inline U lerp_table_lookup_int(U data[(1<<IntBits)+1]) const {
+    inline U lerp_table_lookup_int(U data[]) const {
         unsigned int pos = uipart();
         return lerp_by_fract_int<U, UseBits>(data[pos], data[pos+1]);
     }
@@ -224,19 +224,19 @@ public:
     /// Untested... I've started it to get a sin/cos readout for rotaryorgan, but decided to use table-less solution instead
     /// Do not assume it works, because it most probably doesn't
     template<class U, int UseBits> 
-    inline U lerp_table_lookup_int_shift(U data[(1<<IntBits)+1], unsigned int shift) {
+    inline U lerp_table_lookup_int_shift(U data[], unsigned int shift) {
         unsigned int pos = (uipart() + shift) & ((1 << IntBits) - 1);
         return lerp_by_fract_int<U, UseBits>(data[pos], data[pos+1]);
     }
 
     template<class U> 
-    inline U lerp_table_lookup_float(U data[(1<<IntBits)+1]) const {
+    inline U lerp_table_lookup_float(U data[]) const {
         unsigned int pos = uipart();
         return data[pos] + (data[pos+1]-data[pos]) * fpart_as_double();
     }
 
     template<class U> 
-    inline U lerp_table_lookup_float_mask(U data[(1<<IntBits)+1], unsigned int mask) const {
+    inline U lerp_table_lookup_float_mask(U data[], unsigned int mask) const {
         unsigned int pos = ui64part() & mask;
         // printf("full = %lld pos = %d + %f\n", value, pos, fpart_as_double());
         return data[pos] + (data[pos+1]-data[pos]) * fpart_as_double();
