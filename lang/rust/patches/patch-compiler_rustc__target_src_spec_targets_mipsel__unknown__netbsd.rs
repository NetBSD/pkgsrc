$NetBSD: patch-compiler_rustc__target_src_spec_targets_mipsel__unknown__netbsd.rs,v 1.4 2026/06/11 07:00:57 wiz Exp $

Let's see if turning off thread local storage makes a difference...

--- compiler/rustc_target/src/spec/targets/mipsel_unknown_netbsd.rs.orig	2024-08-05 20:02:56.368978562 +0000
+++ compiler/rustc_target/src/spec/targets/mipsel_unknown_netbsd.rs
@@ -23,6 +23,7 @@ pub(crate) fn target() -> Target {
             llvm_abiname: LlvmAbi::O32,
             mcount: "__mcount".into(),
             endian: Endian::Little,
+            has_thread_local: false, // Let's see if there's a difference...
             ..base
         },
     }
