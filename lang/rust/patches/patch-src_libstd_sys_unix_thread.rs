$NetBSD: patch-src_libstd_sys_unix_thread.rs,v 1.5 2019/03/03 09:16:21 he Exp $

Fix stack-clash on SunOS.

--- src/libstd/sys/unix/thread.rs.orig	2018-07-30 22:15:53.000000000 +0000
+++ src/libstd/sys/unix/thread.rs
@@ -300,7 +300,7 @@ pub mod guard {
 
         let stackaddr = get_stack_start_aligned()?;
 
-        if cfg!(target_os = "linux") {
+        if cfg!(any(target_os = "linux", target_os = "solaris")) {
             // Linux doesn't allocate the whole stack right away, and
             // the kernel has its own stack-guard mechanism to fault
             // when growing too close to an existing mapping.  If we map
