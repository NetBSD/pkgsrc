$NetBSD: patch-sdk_cmake_modules_sdklib__libraries.cmake,v 1.1 2025/02/15 07:40:13 wiz Exp $

* Fix to find libcrypto++
* Add libinotify check

--- sdk/cmake/modules/sdklib_libraries.cmake.orig	2025-01-24 13:56:57.000000000 +0100
+++ sdk/cmake/modules/sdklib_libraries.cmake
@@ -95,9 +95,12 @@ macro(load_sdklib_libraries)
 
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
-        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcrypto++)
+        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcryptopp)
         target_link_libraries(SDKlib PUBLIC PkgConfig::cryptopp) # TODO: Private for SDK core
 
+        pkg_check_modules(inotify REQUIRED IMPORTED_TARGET libinotify)
+        target_link_libraries(SDKlib PRIVATE PkgConfig::inotify)
+
         pkg_check_modules(sodium REQUIRED IMPORTED_TARGET libsodium)
         target_link_libraries(SDKlib PRIVATE PkgConfig::sodium)
 
