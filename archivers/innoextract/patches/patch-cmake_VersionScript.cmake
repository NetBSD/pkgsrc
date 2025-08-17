$NetBSD: patch-cmake_VersionScript.cmake,v 1.1 2025/08/17 08:36:49 wiz Exp $

cmake 4 compatibility
https://github.com/dscharrer/innoextract/commit/83d0bf4365b09ddd17dddb400ba5d262ddf16fb8

--- cmake/VersionScript.cmake.orig	2025-08-17 08:35:15.936455107 +0000
+++ cmake/VersionScript.cmake
@@ -17,7 +17,7 @@
 #    misrepresented as being the original software.
 # 3. This notice may not be removed or altered from any source distribution.
 
-cmake_minimum_required(VERSION 2.8)
+cmake_minimum_required(VERSION 2.8...3.19)
 
 # CMake script that reads a VERSION file and the current git history and the calls configure_file().
 # This is used by version_file() in VersionString.cmake
