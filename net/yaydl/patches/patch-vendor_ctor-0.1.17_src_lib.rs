$NetBSD: patch-vendor_ctor-0.1.17_src_lib.rs,v 1.1 2021/01/09 21:33:04 pin Exp $

Add NetBSD support

--- ../vendor/ctor-0.1.17/src/lib.rs.orig	2021-01-09 21:09:02.640198200 +0100
+++ ../vendor/ctor-0.1.17/src/lib.rs
@@ -99,6 +99,7 @@
 /// #[used]
 /// #[cfg_attr(any(target_os = "linux", target_os = "android"), link_section = ".init_array")]
 /// #[cfg_attr(target_os = "freebsd", link_section = ".init_array")]
+/// #[cfg_attr(target_os = "netbsd", link_section = ".init_array")]
 /// #[cfg_attr(any(target_os = "macos", target_os = "ios"), link_section = "__DATA,__mod_init_func")]
 /// #[cfg_attr(target_os = "windows", link_section = ".CRT$XCU")]
 /// static FOO: extern fn() = {
@@ -140,7 +141,7 @@
                 .expect("Unable to create identifier");
 
         let output = quote!(
-            #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "macos", target_os = "ios", windows)))]
+            #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd", target_os = "macos", target_os = "ios", windows)))]
             compile_error!("#[ctor] is not supported on the current target");
 
             #(#attrs)*
@@ -150,6 +151,7 @@
             #[allow(non_upper_case_globals)]
             #[cfg_attr(any(target_os = "linux", target_os = "android"), link_section = ".init_array")]
             #[cfg_attr(target_os = "freebsd", link_section = ".init_array")]
+            #[cfg_attr(target_os = "netbsd", link_section = ".init_array")]
             #[cfg_attr(any(target_os = "macos", target_os = "ios"), link_section = "__DATA,__mod_init_func")]
             #[cfg_attr(windows, link_section = ".CRT$XCU")]
             static #ctor_ident
@@ -198,7 +200,7 @@
                 .expect("Unable to create identifier");
 
         let output = quote!(
-            #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "macos", target_os = "ios", windows)))]
+            #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd", target_os = "macos", target_os = "ios", windows)))]
             compile_error!("#[ctor] is not supported on the current target");
 
             // This is mutable, but only by this macro code!
@@ -228,6 +230,7 @@
             #[allow(non_upper_case_globals)]
             #[cfg_attr(any(target_os = "linux", target_os = "android"), link_section = ".init_array")]
             #[cfg_attr(target_os = "freebsd", link_section = ".init_array")]
+            #[cfg_attr(target_os = "netbsd", link_section = ".init_array")]
             #[cfg_attr(any(target_os = "macos", target_os = "ios"), link_section = "__DATA,__mod_init_func")]
             #[cfg_attr(windows, link_section = ".CRT$XCU")]
             static #ctor_ident
@@ -296,7 +299,7 @@
             .expect("Unable to create identifier");
 
     let output = quote!(
-        #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "macos", target_os = "ios", windows)))]
+        #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd", target_os = "macos", target_os = "ios", windows)))]
         compile_error!("#[dtor] is not supported on the current target");
 
         #(#attrs)*
@@ -319,6 +322,7 @@
             #[allow(non_upper_case_globals)]
             #[cfg_attr(any(target_os = "linux", target_os = "android"), link_section = ".init_array")]
             #[cfg_attr(target_os = "freebsd", link_section = ".init_array")]
+            #[cfg_attr(target_os = "netbsd", link_section = ".init_array")]
             #[cfg_attr(windows, link_section = ".CRT$XCU")]
             static __dtor_export
             :
