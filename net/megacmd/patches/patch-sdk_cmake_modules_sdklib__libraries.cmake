$NetBSD: patch-sdk_cmake_modules_sdklib__libraries.cmake,v 1.3 2026/03/27 11:06:04 kikadf Exp $

* Fix to find libcrypto++
* Fix missing icu link library

--- sdk/cmake/modules/sdklib_libraries.cmake.orig	2026-02-18 08:41:33.000000000 +0000
+++ sdk/cmake/modules/sdklib_libraries.cmake
@@ -98,7 +98,7 @@ macro(load_sdklib_libraries)
 
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
-        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcrypto++)
+        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcryptopp)
         target_link_libraries(SDKlib PUBLIC PkgConfig::cryptopp) # TODO: Private for SDK core
 
         pkg_check_modules(sodium REQUIRED IMPORTED_TARGET libsodium)
@@ -110,8 +110,8 @@ macro(load_sdklib_libraries)
         pkg_check_modules(curl REQUIRED IMPORTED_TARGET libcurl)
         target_link_libraries(SDKlib PRIVATE PkgConfig::curl)
 
-        find_package(ICU COMPONENTS uc data REQUIRED)
-        target_link_libraries(SDKlib PRIVATE ICU::uc ICU::data)
+        find_package(ICU COMPONENTS i18n uc data REQUIRED)
+        target_link_libraries(SDKlib PRIVATE ICU::i18n ICU::uc ICU::data)
 
         if(USE_OPENSSL)
             find_package(OpenSSL REQUIRED)
