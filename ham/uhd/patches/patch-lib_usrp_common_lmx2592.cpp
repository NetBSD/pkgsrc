$NetBSD: patch-lib_usrp_common_lmx2592.cpp,v 1.1 2022/04/12 20:10:46 tnn Exp $

Don't conflict with system's offset_t.

--- lib/usrp/common/lmx2592.cpp.orig	2021-12-14 18:37:20.000000000 +0000
+++ lib/usrp/common/lmx2592.cpp
@@ -104,10 +104,10 @@ inline bool abs_less_than_compare(const 
     return std::abs(a) < std::abs(b);
 }
 
-typedef std::pair<double, intermediate_frequency_t> offset_t;
+typedef std::pair<double, intermediate_frequency_t> lmx2592_offset_t;
 
-// comparator that uses absolute value on the first value of an offset_t
-inline bool offset_abs_less_than_compare(const offset_t a, const offset_t b)
+// comparator that uses absolute value on the first value of an lmx2592_offset_t
+inline bool offset_abs_less_than_compare(const lmx2592_offset_t a, const lmx2592_offset_t b)
 {
     return std::abs(a.first) < std::abs(b.first);
 }
@@ -607,7 +607,7 @@ private: // Members
     // 3. Reference to Fvco spur
     // 4. Reference to Flo spur
     // A negative offset indicates the closest spur is at a lower frequency
-    offset_t _get_min_offset_frequency(const uint16_t N,
+    lmx2592_offset_t _get_min_offset_frequency(const uint16_t N,
         const uint32_t fnum,
         const uint32_t fden,
         const int prescaler,
@@ -626,16 +626,16 @@ private: // Members
         // in order to calculate the necessary frequency shift
 
         // Integer Boundary:
-        const offset_t ib_spur = {_get_closest_spur_offset(frf_in, pfd_freq), FRF_IN};
+        const lmx2592_offset_t ib_spur = {_get_closest_spur_offset(frf_in, pfd_freq), FRF_IN};
 
         // PFD Offset Spur:
-        const offset_t pfd_offset_spur = {_get_closest_spur_offset(fvco, pfd_freq), FVCO};
+        const lmx2592_offset_t pfd_offset_spur = {_get_closest_spur_offset(fvco, pfd_freq), FVCO};
 
         // Reference to Fvco Spur:
-        const offset_t fvco_spur = {_get_closest_spur_offset(fvco, fref), FVCO};
+        const lmx2592_offset_t fvco_spur = {_get_closest_spur_offset(fvco, fref), FVCO};
 
         // Reference to F_lo Spur:
-        const offset_t flo_spur = {_get_closest_spur_offset(flo, fref), FLO};
+        const lmx2592_offset_t flo_spur = {_get_closest_spur_offset(flo, fref), FLO};
 
         // use min with special comparator for minimal absolute value
         return std::min({ib_spur, pfd_offset_spur, fvco_spur, flo_spur},
