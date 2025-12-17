$NetBSD: patch-cmake_Rust.cmake,v 1.1 2025/12/17 19:05:30 vins Exp $

Do not override RUSTFLAGS.

--- cmake/Rust.cmake.orig	2025-12-17 17:43:49.382254484 +0000
+++ cmake/Rust.cmake
@@ -21,7 +21,6 @@ else()
 endif()
 
 set(rust_profile $<IF:$<CONFIG:Debug>,debug,$<IF:$<CONFIG:RelWithDebInfo>,release-with-debug,release>>)
-set(rust_debugflags "$<$<CONFIG:Debug>:-g>$<$<CONFIG:RelWithDebInfo>:-g>")
 
 option(WITH_GETTEXT "Build with gettext localization support. Requires `msgfmt` to work." ON)
 # Enable gettext feature unless explicitly disabled.
