$NetBSD: patch-vendor_libc-0.2.180_src_unix_bsd_netbsdlike_netbsd_m68k.rs,v 1.1 2026/05/07 13:16:15 wiz Exp $

Add cpu-specific file for m68k on NetBSD.

--- /dev/null	2026-04-16 15:19:59.503167932 +0000
+++ vendor/libc-0.2.180/src/unix/bsd/netbsdlike/netbsd/m68k.rs	2026-04-16 15:19:11.760619011 +0000
@@ -0,0 +1,10 @@
+use crate::prelude::*;
+use crate::PT_FIRSTMACH;
+
+pub type __cpu_simple_lock_nv_t = u8;
+
+pub(crate) const _ALIGNBYTES: usize = size_of::<c_int>() - 1;
+
+pub const PT_STEP: c_int = PT_FIRSTMACH + 0;
+pub const PT_GETREGS: c_int = PT_FIRSTMACH + 1;
+pub const PT_SETREGS: c_int = PT_FIRSTMACH + 2;
