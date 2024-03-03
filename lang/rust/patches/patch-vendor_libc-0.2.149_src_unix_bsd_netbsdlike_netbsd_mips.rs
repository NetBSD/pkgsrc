$NetBSD: patch-vendor_libc-0.2.149_src_unix_bsd_netbsdlike_netbsd_mips.rs,v 1.1 2024/03/03 14:53:33 he Exp $

Add support for NetBSD/mipsel.

--- vendor/libc-0.2.149/src/unix/bsd/netbsdlike/netbsd/mips.rs.orig	2024-01-08 07:29:24.841727520 +0000
+++ vendor/libc-0.2.149/src/unix/bsd/netbsdlike/netbsd/mips.rs	2024-01-08 07:30:35.869045004 +0000
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
