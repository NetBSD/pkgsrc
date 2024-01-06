$NetBSD: patch-library_std_src_sys_unix_thread.rs,v 1.15 2024/01/06 19:00:19 he Exp $

Fix stack-clash on SunOS.

Undo new(ish) code (from 1.72.0) which attempts to count threads/CPUs
on NetBSD; somehow it is causing crashes in bootstrap() on certain
CPU architectures (i386, powerpc, armv7, but not riscv64, aarch64
or amd64); _cpuset_isset() crashes with SEGV.  And according to
what I hear, the code is bogus; by default threads do not have
affinity to any specific set of CPUs in NetBSD, and trying to
replicate this with a simple C program always results in 0.
So rip the newish code out with prejudice, and instead fallback to
the sysctl() method of getting "number of CPUs" which was used
before (and is still present, following the ripped-out code).

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
