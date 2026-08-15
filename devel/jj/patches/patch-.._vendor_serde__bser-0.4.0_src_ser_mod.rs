$NetBSD: patch-.._vendor_serde__bser-0.4.0_src_ser_mod.rs,v 1.1 2026/08/15 19:26:07 he Exp $

The "bytes" crate used big_endian by "default", so there is
no put_.*_be() functions, only put_.*() functions.  Adapt.

Never built for/on a big-endian target?

--- ../vendor/serde_bser-0.4.0/src/ser/mod.rs.orig	2026-08-15 14:56:34.645542049 +0000
+++ ../vendor/serde_bser-0.4.0/src/ser/mod.rs
@@ -133,7 +133,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_i16_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_i16_be(v);
+        self.scratch.put_i16(v);
     }
 
     #[inline]
@@ -143,7 +143,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_i32_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_i32_be(v);
+        self.scratch.put_i32(v);
     }
 
     #[inline]
@@ -153,7 +153,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_i64_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_i64_be(v);
+        self.scratch.put_i64(v);
     }
 }
 
@@ -255,7 +255,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_f64_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_f64_be(v);
+        self.scratch.put_f64(v);
         Ok(())
     }
 
