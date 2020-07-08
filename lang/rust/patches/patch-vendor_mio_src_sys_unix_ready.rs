$NetBSD: patch-vendor_mio_src_sys_unix_ready.rs,v 1.1 2020/07/08 14:46:14 jperkin Exp $

Support illumos.

--- vendor/mio/src/sys/unix/ready.rs.orig	2020-06-01 17:45:25.000000000 +0000
+++ vendor/mio/src/sys/unix/ready.rs
@@ -110,7 +110,7 @@ const LIO: usize   = 0b100000;
 const LIO: usize   = 0b000000;
 
 
-#[cfg(any(target_os = "linux", target_os = "android", target_os = "solaris"))]
+#[cfg(any(target_os = "linux", target_os = "android", target_os = "solaris", target_os = "illumos"))]
 const PRI: usize = ::libc::EPOLLPRI as usize;
 
 
@@ -241,7 +241,7 @@ impl UnixReady {
     /// [`Poll`]: struct.Poll.html
     #[inline]
     #[cfg(any(target_os = "linux",
-        target_os = "android", target_os = "solaris"))]
+        target_os = "android", target_os = "solaris", target_os = "illumos"))]
     pub fn priority() -> UnixReady {
         UnixReady(ready_from_usize(PRI))
     }
@@ -368,7 +368,7 @@ impl UnixReady {
     /// [`Poll`]: struct.Poll.html
     #[inline]
     #[cfg(any(target_os = "linux",
-        target_os = "android", target_os = "solaris"))]
+        target_os = "android", target_os = "solaris", target_os = "illumos"))]
     pub fn is_priority(&self) -> bool {
         self.contains(ready_from_usize(PRI))
     }
@@ -459,7 +459,7 @@ impl fmt::Debug for UnixReady {
             #[allow(deprecated)]
             (UnixReady::aio(), "Aio"),
             #[cfg(any(target_os = "linux",
-                target_os = "android", target_os = "solaris"))]
+                target_os = "android", target_os = "solaris", target_os = "illumos"))]
             (UnixReady::priority(), "Priority"),
         ];
 
