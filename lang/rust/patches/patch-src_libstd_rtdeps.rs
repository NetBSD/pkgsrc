$NetBSD: patch-src_libstd_rtdeps.rs,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Support PKGSRC_USE_SSP (ugly for now).
Add umem.

--- src/libstd/rtdeps.rs.orig	2016-08-16 01:54:35.000000000 +0000
+++ src/libstd/rtdeps.rs
@@ -43,8 +43,10 @@ extern {}
 
 #[cfg(target_os = "solaris")]
 #[link(name = "socket")]
-#[link(name = "posix4")]
 #[link(name = "pthread")]
+// pkgsrc hack until I can figure out how to pass it through properly
+#[link(name = "ssp")]
+#[link(name = "umem")]
 extern {}
 
 // For PNaCl targets, nacl_io is a Pepper wrapper for some IO functions
