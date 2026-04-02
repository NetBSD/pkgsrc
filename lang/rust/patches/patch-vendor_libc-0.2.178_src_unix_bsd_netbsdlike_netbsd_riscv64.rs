$NetBSD: patch-vendor_libc-0.2.178_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.1 2026/04/02 19:06:35 wiz Exp $

Unbreak this module.
These changes have been submitted upstream, but apparently not
in time for this rust release.  Next time, perhaps...

--- vendor/libc-0.2.178/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2026-03-06 20:53:35.722752261 +0000
+++ vendor/libc-0.2.178/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -2,17 +2,9 @@ use crate::prelude::*;
 use crate::PT_FIRSTMACH;
 
 pub type __greg_t = u64;
-pub type __cpu_simple_lock_nv_t = c_int;
-pub type __gregset = [__greg_t; _NGREG];
-pub type __fregset = [__fpreg; _NFREG];
-
-s! {
-    pub struct mcontext_t {
-        pub __gregs: __gregset,
-        pub __fregs: __fregset,
-        __spare: [crate::__greg_t; 7],
-    }
-}
+pub type __cpu_simple_lock_nv_t = c_uint;
+pub type __gregset_t = [__greg_t; _NGREG];
+pub type __fregset_t = [__fpreg; _NFREG];
 
 s_no_extra_traits! {
     pub union __fpreg {
@@ -21,11 +13,19 @@ s_no_extra_traits! {
     }
 }
 
+s! {
+    pub struct mcontext_t {
+        pub __gregs: __gregset_t,
+        pub __fregs: __fregset_t,
+        __spare: [crate::__greg_t; 7],
+    }
+}
+
 cfg_if! {
     if #[cfg(feature = "extra_traits")] {
         impl PartialEq for __fpreg {
             fn eq(&self, other: &Self) -> bool {
-                unsafe { self.u_u64 == other.u_u64 }
+                unsafe { self.u_u64 == other.u_u64 || self.u_d == other.u_d }
             }
         }
         impl Eq for __fpreg {}
@@ -37,7 +37,10 @@ cfg_if! {
     }
 }
 
-pub(crate) const _ALIGNBYTES: usize = size_of::<c_long>() - 1;
+// gcc for riscv64 defines `BIGGEST_ALIGNMENT`, but it's mesured in bits.
+pub(crate) const __BIGGEST_ALIGNMENT_IN_BITS__: usize = 128;
+// `_ALIGNBYTES` is measured in, well, bytes.
+pub(crate) const _ALIGNBYTES: usize = (__BIGGEST_ALIGNMENT_IN_BITS__ / 8) - 1;
 
 pub const PT_GETREGS: c_int = PT_FIRSTMACH + 0;
 pub const PT_SETREGS: c_int = PT_FIRSTMACH + 1;
