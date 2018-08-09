$NetBSD: patch-src_libstd_sys_unix_thread.rs,v 1.4 2018/08/09 17:04:03 jperkin Exp $

Fix stack-clash on SunOS.

--- src/libstd/sys/unix/thread.rs.orig	2018-07-30 22:15:53.000000000 +0000
+++ src/libstd/sys/unix/thread.rs
@@ -309,7 +309,7 @@ pub mod guard {
 
         let stackaddr = get_stack_start_aligned()?;
 
-        if cfg!(target_os = "linux") {
+        if cfg!(any(target_os = "linux", target_os = "solaris")) {
             // Linux doesn't allocate the whole stack right away, and
             // the kernel has its own stack-guard mechanism to fault
             // when growing too close to an existing mapping.  If we map
@@ -354,7 +354,7 @@ pub mod guard {
     }
 
     pub unsafe fn deinit() {
-        if !cfg!(target_os = "linux") {
+        if cfg!(not(any(target_os = "linux", target_os = "solaris"))) {
             if let Some(stackaddr) = get_stack_start_aligned() {
                 // Remove the protection on the guard page.
                 // FIXME: we cannot unmap the page, because when we mmap()
