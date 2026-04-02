$NetBSD: patch-vendor_libc-0.2.177_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.1 2026/04/02 19:06:34 wiz Exp $

Unbreak this module.

I admit to this entirely being based on "cargo cult" and based on
what the compiler told me, but at least the rust compiler (cross-)builds
for NetBSD/risc64 with this, whereas it did not earlier.

--- vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-11-02 16:57:14.244169978 +0000
+++ vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,28 +1,48 @@
-use PT_FIRSTMACH;
-
 use crate::prelude::*;
+use crate::PT_FIRSTMACH;
 
 pub type __greg_t = u64;
-pub type __cpu_simple_lock_nv_t = c_int;
-pub type __gregset = [__greg_t; _NGREG];
-pub type __fregset = [__freg; _NFREG];
+pub type __cpu_simple_lock_nv_t = c_uint;
+pub type __gregset_t = [__greg_t; _NGREG];
+pub type __fregset_t = [__fpreg; _NFREG];
+
+s_no_extra_traits! {
+    pub union __fpreg {
+        pub u_u64: u64,
+        pub u_d: c_double,
+    }
+}
 
 s! {
     pub struct mcontext_t {
-        pub __gregs: __gregset,
-        pub __fregs: __fpregset,
+        pub __gregs: __gregset_t,
+        pub __fregs: __fregset_t,
         __spare: [crate::__greg_t; 7],
     }
 }
 
-s_no_extra_traits! {
-    pub union __fpreg {
-        pub u_u64: u64,
-        pub u_d: c_double,
+cfg_if! {
+    if #[cfg(feature = "extra_traits")] {
+        impl PartialEq for __fpreg {
+            fn eq(&self, other: &__fpreg) -> bool {
+                unsafe { self.u_u64 == other.u_u64 || self.u_d == other.u_d }
+            }
+        }
+        impl Eq for __fpreg {}
+        impl hash::Hash for __fpreg {
+            fn hash<H: hash::Hasher>(&self, state: &mut H) {
+                unsafe {
+                    self.u_u64.hash(state);
+                }
+            }
+        }
     }
 }
 
-pub(crate) const _ALIGNBYTES: usize = size_of::<c_long>() - 1;
+// gcc for riscv64 defines `BIGGEST_ALIGNMENT`, but it's mesured in bits.
+pub(crate) const __BIGGEST_ALIGNMENT_IN_BITS__: usize = 128;
+// `_ALIGNBYTES` is measured in, well, bytes.
+pub(crate) const _ALIGNBYTES: usize = (__BIGGEST_ALIGNMENT_IN_BITS__ / 8) - 1;
 
 pub const PT_GETREGS: c_int = PT_FIRSTMACH + 0;
 pub const PT_SETREGS: c_int = PT_FIRSTMACH + 1;
