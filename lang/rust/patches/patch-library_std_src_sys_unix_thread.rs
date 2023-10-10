$NetBSD: patch-library_std_src_sys_unix_thread.rs,v 1.13 2023/10/10 13:12:33 pin Exp $

Fix stack-clash on SunOS.

--- library/std/src/sys/unix/thread.rs.orig	2020-10-07 07:53:22.000000000 +0000
+++ library/std/src/sys/unix/thread.rs
@@ -752,7 +752,7 @@ pub mod guard {
         let page_size = os::page_size();
         PAGE_SIZE.store(page_size, Ordering::Relaxed);
 
-        if cfg!(all(target_os = "linux", not(target_env = "musl"))) {
+        if cfg!(any(target_os = "solaris", all(target_os = "linux", not(target_env = "musl")))) {
             // Linux doesn't allocate the whole stack right away, and
             // the kernel has its own stack-guard mechanism to fault
             // when growing too close to an existing mapping. If we map
