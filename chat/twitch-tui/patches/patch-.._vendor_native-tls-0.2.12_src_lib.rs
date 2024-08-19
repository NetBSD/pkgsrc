$NetBSD: patch-.._vendor_native-tls-0.2.12_src_lib.rs,v 1.1 2024/08/19 23:58:19 schmonz Exp $

On all platforms, use OpenSSL as determined by pkgsrc.
<https://github.com/sfackler/rust-native-tls/pull/291#issuecomment-2079542215>

--- ../vendor/native-tls-0.2.12/src/lib.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/native-tls-0.2.12/src/lib.rs
@@ -103,16 +103,8 @@ use std::fmt;
 use std::io;
 use std::result;
 
-#[cfg(not(any(target_os = "windows", target_vendor = "apple",)))]
 #[macro_use]
 extern crate log;
-#[cfg(any(target_vendor = "apple",))]
-#[path = "imp/security_framework.rs"]
-mod imp;
-#[cfg(target_os = "windows")]
-#[path = "imp/schannel.rs"]
-mod imp;
-#[cfg(not(any(target_vendor = "apple", target_os = "windows",)))]
 #[path = "imp/openssl.rs"]
 mod imp;
 
