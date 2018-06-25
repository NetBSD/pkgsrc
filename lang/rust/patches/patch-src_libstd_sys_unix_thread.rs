$NetBSD: patch-src_libstd_sys_unix_thread.rs,v 1.3 2018/06/25 13:31:11 ryoon Exp $

--- src/libstd/sys/unix/thread.rs.orig	2018-06-24 22:42:29.203295357 +0000
+++ src/libstd/sys/unix/thread.rs
@@ -326,13 +326,22 @@ pub mod guard {
             // Reallocate the last page of the stack.
             // This ensures SIGBUS will be raised on
             // stack overflow.
-            let result = mmap(stackaddr, PAGE_SIZE, PROT_NONE,
+            // Systems which enforce strict PAX MPROTECT do not allow
+            // to mprotect() a mapping with less restrictive permissions
+            // than the initial mmap() used, so we mmap() here with
+            // read/write permissions and only then mprotect() it to
+            // no permissions at all. See issue #50313.
+            let result = mmap(stackaddr, PAGE_SIZE, PROT_READ | PROT_WRITE,
                               MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0);
-
             if result != stackaddr || result == MAP_FAILED {
                 panic!("failed to allocate a guard page");
             }
 
+            let result = mprotect(stackaddr, PAGE_SIZE, PROT_NONE);
+            if result != 0 {
+                panic!("failed to protect the guard page");
+            }
+
             let guardaddr = stackaddr as usize;
             let offset = if cfg!(target_os = "freebsd") {
                 2
