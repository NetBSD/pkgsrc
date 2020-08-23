$NetBSD: patch-src_main.rs,v 1.1 2020/08/23 14:57:43 kamil Exp $

Use libc for setlocale() to fix non-ASCII character printing.
https://github.com/hrkfdn/ncspot/issues/221

--- src/main.rs.orig	2020-08-13 08:27:21.000000000 +0000
+++ src/main.rs
@@ -47,6 +47,8 @@ use clap::{App, Arg};
 use cursive::traits::Identifiable;
 use cursive::{Cursive, CursiveExt};
 
+use std::ffi::CString;
+
 use librespot_core::authentication::Credentials;
 use librespot_core::cache::Cache;
 use librespot_playback::audio_backend;
@@ -141,6 +143,9 @@ struct UserDataInner {
 }
 
 fn main() {
+    unsafe {
+        libc::setlocale(libc::LC_ALL, CString::new("").unwrap().as_ptr());
+    }
     let backends = {
         let backends: Vec<&str> = audio_backend::BACKENDS.iter().map(|b| b.0).collect();
         format!("Audio backends: {}", backends.join(", "))
