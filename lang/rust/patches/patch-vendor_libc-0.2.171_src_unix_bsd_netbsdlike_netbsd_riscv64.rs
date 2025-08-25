$NetBSD: patch-vendor_libc-0.2.171_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.1 2025/08/25 17:51:13 wiz Exp $

Unbreak this module.

I admit to this entirely being based on "cargo cult", but at least
the rust compiler (cross-)builds for NetBSD/risc64 with this,
whereas it did not earlier.

--- vendor/libc-0.2.171/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-05-19 22:03:59.982023413 +0000
+++ vendor/libc-0.2.171/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,24 +1,70 @@
-use PT_FIRSTMACH;
+use crate::PT_FIRSTMACH;
 
 use crate::prelude::*;
 
 pub type __greg_t = u64;
 pub type __cpu_simple_lock_nv_t = c_int;
 pub type __gregset = [__greg_t; _NGREG];
-pub type __fregset = [__freg; _NFREG];
+pub type __fregset = [__fpreg; _NFREG];
 
-s! {
+s_no_extra_traits! {
+    pub union __fpreg {
+        #[cfg(libc_union)]
+        pub u_u64: u64,
+        pub u_d: c_double,
+    }
     pub struct mcontext_t {
         pub __gregs: __gregset,
-        pub __fregs: __fpregset,
-        __spare: [crate::__greg_t; 7],
+        pub __fregs: __fregset,
+        __spare: [crate::__greg_t; 7],
     }
 }
 
-s_no_extra_traits! {
-    pub union __fpreg {
-        pub u_u64: u64,
-        pub u_d: c_double,
+cfg_if! {
+    if #[cfg(feature = "extra_traits")] {
+//      use ::self::fmt;
+//      use ::self::hash;
+        use core::marker::Copy;
+        use core::clone::Clone;
+        #[cfg(libc_union)]
+        impl PartialEq for __fpreg {
+            fn eq(&self, other: &__fpreg) -> bool {
+                unsafe {
+                    self.u_64 == other.u_64
+                        || self.u_d == other.u_d
+                }
+            }
+        }
+        #[cfg(libc_union)]
+        impl Eq for __fpreg {}
+        #[cfg(libc_union)]
+        impl ::fmt::Debug for __fpreg {
+            fn fmt(&self, f: &mut ::fmt::Formatter) -> ::fmt::Result {
+                unsafe {
+                    f.debug_struct("__fpreg")
+                        .field("u_u64", &self.u_64)
+                        .field("u_d", &self.u_d)
+                        .finish()
+                }
+            }
+        }
+        #[cfg(libc_union)]
+        impl ::hash::Hash for __fpreg {
+            fn hash<H: ::hash::Hasher>(&self, state: &mut H) {
+                unsafe {
+                    self.u_64.hash(state);
+                    self.u_d.hash(state);
+                }
+            }
+        }
+        #[cfg(libc_union)]
+        impl ::Copy for __fpreg {}
+        #[cfg(libc_union)]
+        impl ::Clone for __fpreg {
+            fn clone(&self) -> __fpreg {
+                *self
+            }
+        }
     }
 }
 
