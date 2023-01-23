$NetBSD: patch-vendor_libc-0.2.126_src_unix_bsd_netbsdlike_netbsd_mips.rs,v 1.1 2023/01/23 18:49:04 he Exp $

Replicate patch from unversioned libc.

--- vendor/libc-0.2.126/src/unix/bsd/netbsdlike/netbsd/mips.rs.orig	2022-12-28 21:30:25.222843485 +0000
+++ vendor/libc-0.2.126/src/unix/bsd/netbsdlike/netbsd/mips.rs
@@ -0,0 +1,22 @@
+use PT_FIRSTMACH;
+
+pub type c_long = i32;
+pub type c_ulong = u32;
+pub type c_char = i8;
+pub type __cpu_simple_lock_nv_t = ::c_int;
+
+// should be pub(crate), but that requires Rust 1.18.0
+cfg_if! {
+    if #[cfg(libc_const_size_of)] {
+        #[doc(hidden)]
+        pub const _ALIGNBYTES: usize = ::mem::size_of::<::c_longlong>() - 1;
+    } else {
+        #[doc(hidden)]
+        pub const _ALIGNBYTES: usize = 8 - 1;
+    }
+}
+
+pub const PT_GETREGS: ::c_int = PT_FIRSTMACH + 1;
+pub const PT_SETREGS: ::c_int = PT_FIRSTMACH + 2;
+pub const PT_GETFPREGS: ::c_int = PT_FIRSTMACH + 3;
+pub const PT_SETFPREGS: ::c_int = PT_FIRSTMACH + 4;
