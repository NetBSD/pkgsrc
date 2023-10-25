$NetBSD: patch-library_std_src_sys_unix_thread.rs,v 1.14 2023/10/25 05:50:43 pin Exp $

Fix stack-clash on SunOS.
Undo new way of counting the number of cores we have affinity to
on NetBSD, untli the cpuid_t definition is properly fixed, since
this will get a type error otherwise.  Earlier, this caused a crash
on our 32-bit ports.

--- library/std/src/sys/unix/thread.rs.orig	2020-10-07 07:53:22.000000000 +0000
+++ library/std/src/sys/unix/thread.rs
@@ -352,29 +352,6 @@ pub fn available_parallelism() -> io::Re
                 }
             }
 
-            #[cfg(target_os = "netbsd")]
-            {
-                unsafe {
-                    let set = libc::_cpuset_create();
-                    if !set.is_null() {
-                        let mut count: usize = 0;
-                        if libc::pthread_getaffinity_np(libc::pthread_self(), libc::_cpuset_size(set), set) == 0 {
-                            for i in 0..u64::MAX {
-                                match libc::_cpuset_isset(i, set) {
-                                    -1 => break,
-                                    0 => continue,
-                                    _ => count = count + 1,
-                                }
-                            }
-                        }
-                        libc::_cpuset_destroy(set);
-                        if let Some(count) = NonZeroUsize::new(count) {
-                            return Ok(count);
-                        }
-                    }
-                }
-            }
-
             let mut cpus: libc::c_uint = 0;
             let mut cpus_size = crate::mem::size_of_val(&cpus);
 
@@ -812,7 +789,7 @@ pub mod guard {
         let page_size = os::page_size();
         PAGE_SIZE.store(page_size, Ordering::Relaxed);
 
-        if cfg!(all(target_os = "linux", not(target_env = "musl"))) {
+        if cfg!(any(target_os = "solaris", all(target_os = "linux", not(target_env = "musl")))) {
             // Linux doesn't allocate the whole stack right away, and
             // the kernel has its own stack-guard mechanism to fault
             // when growing too close to an existing mapping. If we map
