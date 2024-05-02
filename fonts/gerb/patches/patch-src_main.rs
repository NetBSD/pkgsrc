$NetBSD: patch-src_main.rs,v 1.1 2024/05/02 11:25:38 he Exp $

--- src/main.rs.orig	2023-04-27 19:58:25.000000000 +0000
+++ src/main.rs
@@ -22,6 +22,7 @@
 #![deny(clippy::dbg_macro)]
 
 use gerb::prelude::*;
+use std::ffi::c_char;
 use gtk::glib::{OptionArg, OptionFlags};
 
 fn main() {
@@ -30,7 +31,7 @@ fn main() {
     let app = Application::new();
     app.add_main_option(
         "ufo",
-        glib::Char('u' as i8),
+        glib::Char('u' as c_char),
         OptionFlags::IN_MAIN,
         OptionArg::Filename,
         "UFO project path to load on launch",
@@ -38,7 +39,7 @@ fn main() {
     );
     app.add_main_option(
         "version",
-        glib::Char('v' as i8),
+        glib::Char('v' as c_char),
         OptionFlags::IN_MAIN,
         OptionArg::None,
         "show version",
