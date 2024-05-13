$NetBSD: patch-.._vendor_native-tls-0.2.11_src_lib.rs,v 1.2 2024/05/13 20:19:04 schmonz Exp $

On all platforms, use OpenSSL as determined by pkgsrc.
<https://github.com/sfackler/rust-native-tls/pull/291#issuecomment-2079542215>

--- ../vendor/native-tls-0.2.11/src/lib.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/native-tls-0.2.11/src/lib.rs
@@ -98,26 +98,14 @@
 #![warn(missing_docs)]
 #![cfg_attr(docsrs, feature(doc_cfg))]
 
-#[macro_use]
-#[cfg(any(target_os = "macos", target_os = "ios"))]
-extern crate lazy_static;
-
 use std::any::Any;
 use std::error;
 use std::fmt;
 use std::io;
 use std::result;
 
-#[cfg(not(any(target_os = "macos", target_os = "windows", target_os = "ios")))]
 #[macro_use]
 extern crate log;
-#[cfg(any(target_os = "macos", target_os = "ios"))]
-#[path = "imp/security_framework.rs"]
-mod imp;
-#[cfg(target_os = "windows")]
-#[path = "imp/schannel.rs"]
-mod imp;
-#[cfg(not(any(target_os = "macos", target_os = "windows", target_os = "ios")))]
 #[path = "imp/openssl.rs"]
 mod imp;
 
