$NetBSD: patch-kde-modules_KDEMetaInfoPlatformCheck.cmake,v 1.1 2022/04/25 03:04:59 markd Exp $

Add NetBSD to supported platforms

--- kde-modules/KDEMetaInfoPlatformCheck.cmake.orig	2022-03-30 13:04:06.000000000 +0000
+++ kde-modules/KDEMetaInfoPlatformCheck.cmake
@@ -38,6 +38,10 @@ if (NOT "${KF_IGNORE_PLATFORM_CHECK}")
                 if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
                     set(_MetainfoFoundSupportedPlatform true)
                 endif()
+            elseif (${CMAKE_MATCH_1} STREQUAL "NetBSD")
+                if (CMAKE_SYSTEM_NAME MATCHES "NetBSD")
+                    set(_MetainfoFoundSupportedPlatform true)
+                endif()
             elseif (${CMAKE_MATCH_1} STREQUAL "Windows")
                 if (WIN32)
                     set(_MetainfoFoundSupportedPlatform true)
