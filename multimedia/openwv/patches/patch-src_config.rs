$NetBSD: patch-src_config.rs,v 1.1 2026/01/21 13:59:45 ryoon Exp $

* Load .wvd data from file. Taken from OpenBSD Ports.

--- src/config.rs.orig	2026-01-20 13:27:18.000000000 +0000
+++ src/config.rs
@@ -3,16 +3,11 @@ pub const CONFIG: OpenWvConfig = OpenWvConfig {
 /// go in a configuration file. See the comments on the structs and enums below
 /// for information on the meaning of each parameter.
 pub const CONFIG: OpenWvConfig = OpenWvConfig {
-    widevine_device: include_bytes!("../embedded.wvd"),
     log_level: log::LevelFilter::Info,
     encrypt_client_id: EncryptClientId::Always,
 };
 
 pub struct OpenWvConfig {
-    /// A pywidevine `.wvd` file containing the private key and Client ID to
-    /// present in license requests. You must obtain this on your own.
-    pub widevine_device: &'static [u8],
-
     /// This can be overridden by the OPENWV_LOG environment variable, but some
     /// browsers like Firefox don't let CDMs see the full environment.
     pub log_level: log::LevelFilter,
