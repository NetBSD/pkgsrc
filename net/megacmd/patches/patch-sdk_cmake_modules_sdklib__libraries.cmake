$NetBSD: patch-sdk_cmake_modules_sdklib__libraries.cmake,v 1.2 2025/05/16 19:43:58 wiz Exp $

* Fix to find libcrypto++

--- sdk/cmake/modules/sdklib_libraries.cmake.orig	2025-04-02 09:16:59.000000000 +0200
+++ sdk/cmake/modules/sdklib_libraries.cmake
@@ -91,7 +91,7 @@ macro(load_sdklib_libraries)
 
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
-        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcrypto++)
+        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcryptopp)
         target_link_libraries(SDKlib PUBLIC PkgConfig::cryptopp) # TODO: Private for SDK core
 
         pkg_check_modules(sodium REQUIRED IMPORTED_TARGET libsodium)
