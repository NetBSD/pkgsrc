$NetBSD: patch-kde-modules_KDEMetaInfoPlatformCheck.cmake,v 1.2 2022/09/29 00:36:30 markd Exp $

Add NetBSD to supported platforms

--- kde-modules/KDEMetaInfoPlatformCheck.cmake.orig	2022-08-27 09:14:28.000000000 +0000
+++ kde-modules/KDEMetaInfoPlatformCheck.cmake
@@ -38,6 +38,10 @@ if (NOT "${KF_IGNORE_PLATFORM_CHECK}")
                 if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
                     set(_MetainfoFoundSupportedPlatform true)
                 endif()
+            elseif (${CMAKE_MATCH_1} STREQUAL "NetBSD")
+                if (CMAKE_SYSTEM_NAME MATCHES "NetBSD")
+                    set(_MetainfoFoundSupportedPlatform true)
+                endif()
             elseif (${CMAKE_MATCH_1} STREQUAL "OpenBSD")
                 if (CMAKE_SYSTEM_NAME MATCHES "OpenBSD")
                     set(_MetainfoFoundSupportedPlatform true)
