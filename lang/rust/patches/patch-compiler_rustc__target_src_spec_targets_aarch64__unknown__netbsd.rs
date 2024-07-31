$NetBSD: patch-compiler_rustc__target_src_spec_targets_aarch64__unknown__netbsd.rs,v 1.1 2024/07/31 08:05:50 he Exp $

NetBSD aarch64 has a bug in the thread-local storage implementation,
ref. PR#58154.  Turn it off for now.
Ideally should check whether the version has the fix or not, but
e.g. __NetBSD_Version__ isn't easily available here that I know...

--- compiler/rustc_target/src/spec/targets/aarch64_unknown_netbsd.rs.orig	2024-07-23 19:18:44.116841966 +0000
+++ compiler/rustc_target/src/spec/targets/aarch64_unknown_netbsd.rs
@@ -17,6 +17,7 @@ pub fn target() -> Target {
             mcount: "__mcount".into(),
             max_atomic_width: Some(128),
             stack_probes: StackProbeType::Inline,
+            has_thread_local: false, // ref. NetBSD PR#58154
             ..base::netbsd::opts()
         },
     }
