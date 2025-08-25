$NetBSD: patch-vendor_libc-0.2.168_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.1 2025/08/25 17:51:12 wiz Exp $

Unbreak this module.

I admit to this entirely being based on "cargo cult", but at least
the rust compiler (cross-)builds for NetBSD/risc64 with this,
whereas it did not earlier.

--- vendor/libc-0.2.168/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-06-28 07:45:40.263146414 +0000
+++ vendor/libc-0.2.168/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,4 +1,4 @@
-use PT_FIRSTMACH;
+use crate::PT_FIRSTMACH;
 
 use crate::prelude::*;
 
@@ -8,21 +8,18 @@ pub type c_char = u8;
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
     pub union __fpreg {
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
