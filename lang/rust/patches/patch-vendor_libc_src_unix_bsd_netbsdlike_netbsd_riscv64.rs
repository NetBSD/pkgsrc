$NetBSD: patch-vendor_libc_src_unix_bsd_netbsdlike_netbsd_riscv64.rs,v 1.3 2023/10/25 05:50:43 pin Exp $

Spec for riscv64.

--- vendor/libc/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2023-07-02 20:13:26.244972364 +0000
+++ vendor/libc/src/unix/bsd/netbsdlike/netbsd/riscv64.rs  2023-07-02 20:13:26.244972364 +0000
@@ -0,0 +1,24 @@
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
+// pub const _MAX_PAGE_SHIFT: u32 = 12;
+
+pub const PT_GETREGS: ::c_int = PT_FIRSTMACH + 0;
+pub const PT_SETREGS: ::c_int = PT_FIRSTMACH + 1;
+pub const PT_GETFPREGS: ::c_int = PT_FIRSTMACH + 2;
+pub const PT_SETFPREGS: ::c_int = PT_FIRSTMACH + 3;
