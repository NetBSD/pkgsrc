$NetBSD: patch-src_libstd_sys_unix_os.rs,v 1.1 2017/02/23 09:35:16 jperkin Exp $

Match prototype (XXX: use POSIX_PTHREAD_SEMANTICS)

--- src/libstd/sys/unix/os.rs.orig	2016-12-20 23:34:55.000000000 +0000
+++ src/libstd/sys/unix/os.rs
@@ -506,7 +506,7 @@ pub fn home_dir() -> Option<PathBuf> {
             // getpwuid_r semantics is different on Illumos/Solaris:
             // http://illumos.org/man/3c/getpwuid_r
             let result = libc::getpwuid_r(me, passwd, buf.as_mut_ptr(),
-                                          buf.capacity());
+                                          buf.capacity() as libc::c_int);
             if result.is_null() { None } else { Some(()) }
         }
 
