$NetBSD: patch-vendor_memchr-2.7.5_src_vector.rs,v 1.1 2026/09/30 20:01:30 wiz Exp $

Apply fix for big-endian aarch64 from
https://github.com/BurntSushi/memchr/pull/222

--- vendor/memchr-2.7.5/src/vector.rs.orig	2026-07-14 15:13:08.000000000 +0000
+++ vendor/memchr-2.7.5/src/vector.rs
@@ -319,6 +319,7 @@ mod aarch64neon {
         }
 
         #[inline(always)]
+        #[cfg(target_endian = "little")]
         unsafe fn movemask(self) -> NeonMoveMask {
             let asu16s = vreinterpretq_u16_u8(self);
             let mask = vshrn_n_u16(asu16s, 4);
@@ -328,6 +329,18 @@ mod aarch64neon {
         }
 
         #[inline(always)]
+        #[cfg(target_endian = "big")]
+        unsafe fn movemask(self) -> NeonMoveMask {
+            // Swap the endianness of each 16-bit input.
+            let asu16s = vreinterpretq_u16_u8(vrev16q_u8(self));
+            let mask = vshrn_n_u16(asu16s, 4);
+            let asu64 = vreinterpret_u64_u8(mask);
+            // Use `swap_bytes` to swap the endianness of the 64-bit output.
+            let scalar64 = vget_lane_u64(asu64, 0).swap_bytes();
+            NeonMoveMask(scalar64 & 0x8888888888888888)
+        }
+
+        #[inline(always)]
         unsafe fn cmpeq(self, vector2: Self) -> uint8x16_t {
             vceqq_u8(self, vector2)
         }
