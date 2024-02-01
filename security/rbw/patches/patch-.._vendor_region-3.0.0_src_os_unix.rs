$NetBSD: patch-.._vendor_region-3.0.0_src_os_unix.rs,v 1.1 2024/02/01 11:24:06 pin Exp $

Add unmerged pull request
https://github.com/darfink/region-rs/pull/14/

--- ../vendor/region-3.0.0/src/os/unix.rs.orig	2024-01-24 09:24:43.882972184 +0000
+++ ../vendor/region-3.0.0/src/os/unix.rs
@@ -8,6 +8,12 @@ pub fn page_size() -> usize {
 }
 
 pub unsafe fn alloc(base: *const (), size: usize, protection: Protection) -> Result<*const ()> {
+  #[cfg(not(target_os = "netbsd"))]
+  let prot = protection.to_native();
+  // PROT_MPROTECT usage for avoiding problems with NetBSD pax
+  #[cfg(target_os = "netbsd")]
+  let prot = protection.to_native() | (PROT_READ | PROT_WRITE | PROT_EXEC) << 3;
+
   let mut flags = MAP_PRIVATE | MAP_ANON;
 
   if !base.is_null() {
