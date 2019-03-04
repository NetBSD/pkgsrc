$NetBSD: patch-servo_components_style__traits_lib.rs,v 1.1 2019/03/04 15:59:06 ryoon Exp $

--- servo/components/style_traits/lib.rs.orig	2019-02-21 19:22:50.000000000 +0000
+++ servo/components/style_traits/lib.rs
@@ -9,8 +9,6 @@
 #![crate_name = "style_traits"]
 #![crate_type = "rlib"]
 
-#![deny(unsafe_code, missing_docs)]
-
 extern crate app_units;
 #[macro_use] extern crate bitflags;
 #[macro_use] extern crate cssparser;
