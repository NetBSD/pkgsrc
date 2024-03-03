$NetBSD: patch-library_backtrace_src_symbolize_gimli_elf.rs,v 1.7 2024/03/03 14:53:32 he Exp $

Make NetBSD also find its debug libraries, if present.

--- library/backtrace/src/symbolize/gimli/elf.rs.orig	2022-04-04 09:41:26.000000000 +0000
+++ library/backtrace/src/symbolize/gimli/elf.rs
@@ -304,11 +304,17 @@ fn decompress_zlib(input: &[u8], output:
     }
 }
 
+#[cfg(target_os = "netbsd")]
+const DEBUG_PATH: &[u8] = b"/usr/libdata/debug";
+#[cfg(not(target_os = "netbsd"))]
 const DEBUG_PATH: &[u8] = b"/usr/lib/debug";
 
 fn debug_path_exists() -> bool {
     cfg_if::cfg_if! {
-        if #[cfg(any(target_os = "freebsd", target_os = "hurd", target_os = "linux"))] {
+        if #[cfg(any(target_os = "freebsd",
+                     target_os = "netbsd",
+                     target_os = "hurd",
+                     target_os = "linux"))] {
             use core::sync::atomic::{AtomicU8, Ordering};
             static DEBUG_PATH_EXISTS: AtomicU8 = AtomicU8::new(0);
 
