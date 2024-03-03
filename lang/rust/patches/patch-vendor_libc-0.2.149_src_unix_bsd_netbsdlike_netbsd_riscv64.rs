$NetBSD: patch-vendor_libc-0.2.149_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.1 2024/03/03 14:53:33 he Exp $

Add support for NetBSD/riscv64.

--- vendor/libc-0.2.149/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2024-01-08 07:29:24.841727520 +0000
+++ vendor/libc-0.2.149/src/unix/bsd/netbsdlike/netbsd/riscv64.rs	2024-01-08 07:33:10.924970251 +0000
@@ -0,0 +1,22 @@
+use PT_FIRSTMACH;
+
+pub type c_long = i64;
+pub type c_ulong = u64;
+pub type c_char = u8;
+pub type __cpu_simple_lock_nv_t = ::c_int;
+
+// should be pub(crate), but that requires Rust 1.18.0
+cfg_if! {
+    if #[cfg(libc_const_size_of)] {
+        #[doc(hidden)]
+        pub const _ALIGNBYTES: usize = ::mem::size_of::<::c_long>() - 1;
+    } else {
+        #[doc(hidden)]
+        pub const _ALIGNBYTES: usize = 8 - 1;
+    }
+}
+
+pub const PT_GETREGS: ::c_int = PT_FIRSTMACH + 0;
+pub const PT_SETREGS: ::c_int = PT_FIRSTMACH + 1;
+pub const PT_GETFPREGS: ::c_int = PT_FIRSTMACH + 2;
+pub const PT_SETFPREGS: ::c_int = PT_FIRSTMACH + 3;
