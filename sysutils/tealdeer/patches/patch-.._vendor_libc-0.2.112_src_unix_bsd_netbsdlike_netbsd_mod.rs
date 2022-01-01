$NetBSD: patch-.._vendor_libc-0.2.112_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2022/01/01 19:32:04 bsiegert Exp $

Add definition of execvpe function.
--- ../vendor/libc-0.2.112/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2022-01-01 17:24:14.521129968 +0000
+++ ../vendor/libc-0.2.112/src/unix/bsd/netbsdlike/netbsd/mod.rs	2022-01-01 17:26:38.792598102 +0000
@@ -2164,6 +2164,12 @@
     pub fn fchflags(fd: ::c_int, flags: ::c_ulong) -> ::c_int;
     pub fn lchflags(path: *const ::c_char, flags: ::c_ulong) -> ::c_int;
 
+    pub fn execvpe(
+        file: *const ::c_char,
+        argv: *const *const ::c_char,
+        envp: *const *const ::c_char,
+    ) -> ::c_int;
+
     pub fn extattr_delete_fd(
         fd: ::c_int,
         attrnamespace: ::c_int,
