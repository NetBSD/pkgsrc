$NetBSD: patch-src_vendor_filetime_src_unix.rs,v 1.1 2018/01/04 15:18:51 jperkin Exp $

SunOS does not have lutimes.

--- src/vendor/filetime/src/unix.rs.orig	2017-11-22 23:37:31.000000000 +0000
+++ src/vendor/filetime/src/unix.rs
@@ -14,12 +14,12 @@ pub fn set_file_times(p: &Path, atime: F
     set_file_times_u(p, atime, mtime, libc::utimes)
 }
 
-#[cfg(target_os = "android")]
+#[cfg(any(target_os = "android", target_os = "solaris"))]
 pub fn set_symlink_file_times(_p: &Path, _atime: FileTime, _mtime: FileTime) -> io::Result<()> {
-   Err(io::Error::new(io::ErrorKind::Other, "not supported on Android"))
+   Err(io::Error::new(io::ErrorKind::Other, "not supported"))
 }
 
-#[cfg(not(target_os = "android"))]
+#[cfg(not(any(target_os = "android", target_os = "solaris")))]
 pub fn set_symlink_file_times(p: &Path, atime: FileTime, mtime: FileTime) -> io::Result<()> {
    set_file_times_u(p, atime, mtime, libc::lutimes)
 }
