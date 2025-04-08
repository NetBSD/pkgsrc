$NetBSD: patch-vendor_libc-0.2.167_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.1 2025/04/08 09:31:07 wiz Exp $

Unbreak this module.
Patterned and simplified after patch to vendor/libc-0.2.169..
This one is used during bootstrap build on riscv64.

--- vendor/libc-0.2.167/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-02-17 18:17:27.000000000 +0000
+++ vendor/libc-0.2.167/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,4 +1,4 @@
-use PT_FIRSTMACH;
+use crate::PT_FIRSTMACH;
 
 use crate::prelude::*;
 
@@ -8,15 +8,7 @@ pub type c_char = u8;
 pub type __greg_t = u64;
 pub type __cpu_simple_lock_nv_t = c_int;
 pub type __gregset = [__greg_t; _NGREG];
-pub type __fregset = [__freg; _NFREG];
-
-s! {
-    pub struct mcontext_t {
-        pub __gregs: __gregset,
-        pub __fregs: __fpregset,
-        __spare: [crate::__greg_t; 7],
-    }
-}
+pub type __fregset = [__fpreg; _NFREG];
 
 s_no_extra_traits! {
     #[cfg_attr(feature = "extra_traits", allow(missing_debug_implementations))]
@@ -24,6 +16,11 @@ s_no_extra_traits! {
         pub u_u64: u64,
         pub u_d: c_double,
     }
+    pub struct mcontext_t {
+        pub __gregs: __gregset,
+        pub __fregs: __fregset,
+        __spare: [crate::__greg_t; 7],
+    }
 }
 
 pub(crate) const _ALIGNBYTES: usize = mem::size_of::<c_long>() - 1;
