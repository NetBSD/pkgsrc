$NetBSD: patch-vendor_stacker_src_lib.rs,v 1.6 2022/01/21 23:20:36 he Exp $

Avoid missing pthread_* on older SunOS.

--- vendor/stacker/src/lib.rs.orig	2020-07-13 18:18:17.000000000 +0000
+++ vendor/stacker/src/lib.rs
@@ -407,7 +407,7 @@ cfg_if! {
             );
             Some(mi.assume_init().AllocationBase as usize + get_thread_stack_guarantee() + 0x1000)
         }
-    } else if #[cfg(any(target_os = "linux", target_os="solaris", target_os = "netbsd"))] {
+    } else if #[cfg(any(target_os = "linux", target_os = "netbsd"))] {
         unsafe fn guess_os_stack_limit() -> Option<usize> {
             let mut attr = std::mem::MaybeUninit::<libc::pthread_attr_t>::uninit();
             assert_eq!(libc::pthread_attr_init(attr.as_mut_ptr()), 0);
