$NetBSD: patch-vendor_rand_src_rngs_os.rs,v 1.2 2019/06/13 19:06:30 tnn Exp $

-Explicitly disable getrandom support on SunOS, the test fails.
-https://github.com/rust-random/rand/issues/637

The rand implementation for NetBSD drains a byte from /dev/random on every
rustc invocation, with the intent to ensure /dev/urandom is seeded.
This is inappropriate; seeding the rng should be handled by rc.d scripts only.
The result is that rustc eventually blocks for very long times when generating
temp file names, causing the lang/rust build to take days(!) in some cases.
The fix is to delete the NetBSD specific implementation and instead use the
FreeBSD implementation which relies on the kern.arandom sysctl instead of
/dev/{u,}random.
The bootstrap compiler of course has the same issue so I will raise a PR
with upstream authors to address this.

--- vendor/rand/src/rngs/os.rs.orig	2019-05-20 13:47:25.000000000 +0000
+++ vendor/rand/src/rngs/os.rs
@@ -246,7 +246,7 @@ trait OsRngImpl where Self: Sized {
 // All instances use a single internal file handle, to prevent possible
 // exhaustion of file descriptors.
 #[cfg(any(target_os = "linux", target_os = "android",
-          target_os = "netbsd", target_os = "dragonfly",
+          target_os = "dragonfly",
           target_os = "solaris", target_os = "redox",
           target_os = "haiku", target_os = "emscripten"))]
 mod random_device {
@@ -487,56 +487,6 @@ mod imp {
     }
 }
 
-
-#[cfg(target_os = "netbsd")]
-mod imp {
-    use Error;
-    use super::random_device;
-    use super::OsRngImpl;
-
-    use std::fs::File;
-    use std::io::Read;
-    use std::sync::atomic::{AtomicBool, ATOMIC_BOOL_INIT, Ordering};
-
-    #[derive(Clone, Debug)]
-    pub struct OsRng { initialized: bool }
-
-    impl OsRngImpl for OsRng {
-        fn new() -> Result<OsRng, Error> {
-            random_device::open("/dev/urandom", &|p| File::open(p))?;
-            Ok(OsRng { initialized: false })
-        }
-
-        fn fill_chunk(&mut self, dest: &mut [u8]) -> Result<(), Error> {
-            random_device::read(dest)
-        }
-
-        // Read a single byte from `/dev/random` to determine if the OS RNG is
-        // already seeded. NetBSD always blocks if not yet ready.
-        fn test_initialized(&mut self, dest: &mut [u8], _blocking: bool)
-            -> Result<usize, Error>
-        {
-            static OS_RNG_INITIALIZED: AtomicBool = ATOMIC_BOOL_INIT;
-            if !self.initialized {
-                self.initialized = OS_RNG_INITIALIZED.load(Ordering::Relaxed);
-            }
-            if self.initialized { return Ok(0); }
-
-            info!("OsRng: testing random device /dev/random");
-            let mut file =
-                File::open("/dev/random").map_err(random_device::map_err)?;
-            file.read(&mut dest[..1]).map_err(random_device::map_err)?;
-
-            OS_RNG_INITIALIZED.store(true, Ordering::Relaxed);
-            self.initialized = true;
-            Ok(1)
-        }
-
-        fn method_str(&self) -> &'static str { "/dev/urandom" }
-    }
-}
-
-
 #[cfg(any(target_os = "dragonfly",
           target_os = "haiku",
           target_os = "emscripten"))]
@@ -677,6 +627,7 @@ mod imp {
     }
 
     fn getrandom(buf: &mut [u8], blocking: bool) -> libc::c_long {
+        return -1;
         extern "C" {
             fn syscall(number: libc::c_long, ...) -> libc::c_long;
         }
@@ -824,7 +775,7 @@ mod imp {
 }
 
 
-#[cfg(target_os = "freebsd")]
+#[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
 mod imp {
     extern crate libc;
 
