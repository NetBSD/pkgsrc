$NetBSD: patch-sdk_cmake_modules_sdklib__libraries.cmake,v 1.4 2026/09/22 14:28:56 kikadf Exp $

* Fix to find libcrypto++

--- sdk/cmake/modules/sdklib_libraries.cmake.orig	2026-02-18 08:41:33.000000000 +0000
+++ sdk/cmake/modules/sdklib_libraries.cmake
@@ -98,7 +98,7 @@ macro(load_sdklib_libraries)
 
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
-        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcrypto++)
+        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcryptopp)
         target_link_libraries(SDKlib PUBLIC PkgConfig::cryptopp) # TODO: Private for SDK core
 
         pkg_check_modules(sodium REQUIRED IMPORTED_TARGET libsodium)
