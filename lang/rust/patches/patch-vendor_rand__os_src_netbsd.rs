$NetBSD: patch-vendor_rand__os_src_netbsd.rs,v 1.1 2019/10/02 12:51:43 he Exp $

Use the FreeBSD implementation on NetBSD instead of the
one using /dev/urandom.

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

--- vendor/rand_os/src/netbsd.rs.orig	2019-09-28 20:13:53.155901674 +0000
+++ vendor/rand_os/src/netbsd.rs
@@ -6,52 +6,40 @@
 // option. This file may not be copied, modified, or distributed
 // except according to those terms.
 
-//! Implementation for NetBSD
+//! Implementation for FreeBSD
 
-use rand_core::Error;
-use super::random_device;
+extern crate libc;
+
+use rand_core::{Error, ErrorKind};
 use super::OsRngImpl;
 
-use std::fs::File;
-use std::io::Read;
-use std::sync::atomic::{AtomicBool, Ordering};
-#[allow(deprecated)]  // Required for compatibility with Rust < 1.24.
-use std::sync::atomic::ATOMIC_BOOL_INIT;
+use std::ptr;
+use std::io;
 
 #[derive(Clone, Debug)]
-pub struct OsRng { initialized: bool }
+pub struct OsRng;
 
 impl OsRngImpl for OsRng {
-    fn new() -> Result<OsRng, Error> {
-        random_device::open("/dev/urandom", &|p| File::open(p))?;
-        Ok(OsRng { initialized: false })
-    }
+    fn new() -> Result<OsRng, Error> { Ok(OsRng) }
 
     fn fill_chunk(&mut self, dest: &mut [u8]) -> Result<(), Error> {
-        random_device::read(dest)
-    }
-
-    // Read a single byte from `/dev/random` to determine if the OS RNG is
-    // already seeded. NetBSD always blocks if not yet ready.
-    fn test_initialized(&mut self, dest: &mut [u8], _blocking: bool)
-        -> Result<usize, Error>
-    {
-        #[allow(deprecated)]
-        static OS_RNG_INITIALIZED: AtomicBool = ATOMIC_BOOL_INIT;
-        if !self.initialized {
-            self.initialized = OS_RNG_INITIALIZED.load(Ordering::Relaxed);
+        let mib = [libc::CTL_KERN, libc::KERN_ARND];
+        let mut len = dest.len();
+        let ret = unsafe {
+            libc::sysctl(mib.as_ptr(), mib.len() as libc::c_uint,
+                         dest.as_mut_ptr() as *mut _, &mut len,
+                         ptr::null(), 0)
+        };
+        if ret == -1 || len != dest.len() {
+            return Err(Error::with_cause(
+                ErrorKind::Unavailable,
+                "kern.arandom sysctl failed",
+                io::Error::last_os_error()));
         }
-        if self.initialized { return Ok(0); }
-
-        info!("OsRng: testing random device /dev/random");
-        let mut file =
-            File::open("/dev/random").map_err(random_device::map_err)?;
-        file.read(&mut dest[..1]).map_err(random_device::map_err)?;
-
-        OS_RNG_INITIALIZED.store(true, Ordering::Relaxed);
-        self.initialized = true;
-        Ok(1)
+        Ok(())
     }
 
-    fn method_str(&self) -> &'static str { "/dev/urandom" }
+    fn max_chunk_size(&self) -> usize { 256 }
+
+    fn method_str(&self) -> &'static str { "kern.arandom" }
 }
