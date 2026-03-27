$NetBSD: patch-.._vendor_x11rb-0.13.2_src_xcb__ffi_raw__ffi_ffi.rs,v 1.1 2026/03/27 22:38:33 tnn Exp $

Remove hard-coded libxcb.so paths. pkgsrc links with the correct rpath.
Needed for X11_TYPE=modular.

--- ../vendor/x11rb-0.13.2/src/xcb_ffi/raw_ffi/ffi.rs.orig	2025-10-18 15:36:27.746267128 +0000
+++ ../vendor/x11rb-0.13.2/src/xcb_ffi/raw_ffi/ffi.rs
@@ -35,18 +35,7 @@ pub(crate) mod libxcb_library {
             #[cfg(not(unix))]
             compile_error!("dl-libxcb feature is not supported on non-unix");
 
-            #[cfg(all(unix, target_os = "linux"))]
-            const LIB_NAME: &str = "libxcb.so.1";
-
-            // libtool turns -version-info differently into SONAMES on NetBSD.
-            // Also, the library is apparently not in the default search path, hence use a full path.
-            #[cfg(all(unix, target_os = "netbsd"))]
-            const LIB_NAME: &str = "/usr/X11R7/lib/libxcb.so.2";
-
-            // If we do not know anything, just assume libxcb.so and hope for the best.
-            // This is actually the right thing to do on OpenBSD since the dynamic linker then does
-            // some magic to find the right SONAME.
-            #[cfg(all(unix, not(any(target_os = "linux", target_os = "netbsd"))))]
+            #[cfg(unix)]
             const LIB_NAME: &str = "libxcb.so";
 
             let library = libloading::Library::new(LIB_NAME)
